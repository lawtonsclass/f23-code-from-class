.global bwSIMD
.type bwSIMD, %function
bwSIMD:
  sub sp, sp, #16
  str lr, [sp]
  
  // FIXME: implement the void bwFP(char* pixelsStart, int numPixels)
  // function to convert numPixels pixels to b&w starting at pixelsStart. 
  // numPixels is guaranteed to be a multiple of 16 so that you can use
  // 128-bit registers.

loop:
  cmp w1, #0 // (we'll keep subtracting from numPixels (w1) every time we process more)
  b.le done

  // list of all SIMD instructions: https://developer.arm.com/documentation/dui0801/l/A64-SIMD-Vector-Instructions/A64-SIMD-Vector-instructions-in-alphabetical-order

  // read a chunk of pixels
  ld3 {v0.16B, v1.16B, v2.16B}, [x0]

  // process them
  // extend blue
  uxtl v3.8H, v0.8B
  uxtl2 v4.8H, v0.16B

  // extend green
  uxtl v5.8H, v1.8B
  uxtl2 v6.8H, v1.16B

  // extend red
  uxtl v7.8H, v2.8B
  uxtl2 v8.8H, v2.16B

  add v3.8H, v3.8H, v5.8H
  add v3.8H, v3.8H, v7.8H // v3 = left half r + g + b

  add v4.8H, v4.8H, v6.8H
  add v4.8H, v4.8H, v8.8H // v4 = right half r + g + b

  // put 384 into v5 (copied into every 16-bit chunk)
  movi v5.8H, #0
  movi v6.8H, #128
  add v5.8H, v5.8H, v6.8H
  add v5.8H, v5.8H, v6.8H
  add v5.8H, v5.8H, v6.8H // now v5 holds 384

  cmge v0.8H, v3.8H, v5.8H // compare left half r+g+b with the threshold value
  cmge v1.8H, v4.8H, v5.8H // compare right half r+g+b with the threshold value

  // shink v0 & v1 down into 8 bits again
  xtn v2.8B, v0.8H
  xtn2 v2.16B, v1.8H

  mov v0.16B, v2.16B // v0 holds red
  mov v1.16B, v0.16B // v1 holds green
  mov v2.16B, v0.16B // v2 holds blue

  // write them back to memory
  st3 {v0.16B, v1.16B, v2.16B}, [x0]

  // advance x0
    // v0, v1, & v2 are all 128 bits (16 bytes)
    // so we're reading 48 bytes total
    // the next address we want to read from is 48 bytes from now
  add x0, x0, #48

  // we just processed 16 pixels
  sub w1, w1, #16
  b.al loop
done:

  ldr lr, [sp]
  add sp, sp, #16
  ret
