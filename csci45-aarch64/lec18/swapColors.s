.global swapColorsSIMD
.type swapColorsSIMD, %function
swapColorsSIMD:
  sub sp, sp, #16
  str lr, [sp]
  
  // FIXME: implement the void swapColorsNEON(char* pixelsStart, int numPixels)
  // function to swap the colors of numPixels pixels starting at pixelsStart. 
  // numPixels is guaranteed to be a multiple of 16 so that you can
  // use 128-bit SIMD registers.

loop:
  cmp w1, #0 // (we'll keep subtracting from numPixels (w1) every time we process more)
  ble done

  // read a chunk of pixels
  ld3 {v0.16B, v1.16B, v2.16B}, [x0]

  // process them
  // swap red and green
  mov v3.16B, v1.16B
  mov v1.16B, v2.16B
  mov v2.16B, v3.16B

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
