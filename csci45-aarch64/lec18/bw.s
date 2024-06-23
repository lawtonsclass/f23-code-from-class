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

  // read a chunk of pixels (only into d registers because doing it
  // with v registers is more complicated)
  ld3 {v0.8B, v1.8B, v2.8B}, [x0]
  // .8B means read into the lower half of each register
  // so really we just read into d0, d1, & d2

  // process them

  // extend blue
  uxtl v3.8H, v0.8B // really d0 again here
  // extend green
  uxtl v4.8H, v1.8B
  // extend red
  uxtl v5.8H, v2.8B

  add v3.8H, v3.8H, v4.8H
  add v3.8H, v3.8H, v5.8H // v3 = r + g + b

  // put 384 into v4 (copied into every 16-bit chunk)
  movi v4.8H, #0
  movi v5.8H, #128
  add v4.8H, v4.8H, v5.8H
  add v4.8H, v4.8H, v5.8H
  add v4.8H, v4.8H, v5.8H // now v4 holds 384

  cmge v0.8H, v3.8H, v4.8H // compare r+g+b with the threshold value

  // shink v0 down into 8 bits again
  xtn v3.8B, v0.8H // really we just shrunk v0 down into *d3*

  mov v0.8B, v3.8B // d0 holds red
  mov v1.8B, v0.8B // d1 holds green
  mov v2.8B, v0.8B // d2 holds blue

  // write them back to memory
  st3 {v0.8B, v1.8B, v2.8B}, [x0] // we're really writing d0, d1, & d2

  // advance x0
    // v0, v1, & v2 are all 64 bits (8 bytes)
    // so we're reading 24 bytes total
    // the next address we want to read from is 24 bytes from now
  add x0, x0, #24

  // we just processed 8 pixels
  sub w1, w1, #8
  b.al loop
done:

  ldr lr, [sp]
  add sp, sp, #16
  ret
