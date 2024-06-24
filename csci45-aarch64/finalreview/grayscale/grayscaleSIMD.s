.global grayscaleSIMD
.type grayscaleSIMD, %function
grayscaleSIMD:
  sub sp, sp, #16
  str lr, [sp]
  
  // FIXME: implement the void grayscaleSIMD(char* pixelsStart, int numPixels)
  // function to convert numPixels pixels to b&w starting at pixelsStart. 
  // numPixels is guaranteed to be a multiple of 16 so that you can use
  // 128-bit registers.

  // loop through every pixel, reading a chunk at a time because SIMD
loop:
  cmp w1, #0 // (we'll keep subtracting from numPixels (w1) every time we process more)
  b.le loopend

  // read a chunk of pixels (only into 64-bit registers because we need to
  // extend them to 16 bits)
  ld3 {v0.8B, v1.8B, v2.8B}, [x0]
  // only the left halves of v0, v1, & v2 have data now

  // process them (convert to grayscale)
  // ========begin processing===========

  // Extend v0.left, v1.left, & v2.left into full v registers
  // (converting all the values to 16-bit). We have to do this so that
  // we can add up the RGB values and not lose any information to
  // overflow.
  uxtl v3.8H, v0.8B
  uxtl v4.8H, v1.8B
  uxtl v5.8H, v2.8B

  // Add up the RGB values
  add v3.8H, v3.8H, v4.8H
  add v3.8H, v3.8H, v5.8H
  // now we need to divide them by 3

  // Get the magic constant into each 16-bit slot of a v register
  ldr x2, =magic_number
  ldr w2, [x2]
  dup v0.8H, w2 // dup for duplicate
  // so now the magic number is duplicated 8 times as a 16-bit # in v0

  // multiply the sum in v3 by the magic constant in v0
  // just like multiplying two 2-digit #s makes a 4-digit #, we want
  // to multiply 2 16-bit #s into a 32-bit #
  // mull is mul e*long*ated
  umull v1.4S, v3.4H, v0.4H // multiply the left 64-bits of v3 & v0 into v1 (as 4 32-bit #s)
  umull2 v2.4S, v3.8H, v0.8H // multiply the right 64-bits of v3 & v0 into v2 (as 4 32-bit #s)
  // so v1 holds the *first* 4 pixels, and v2 holds the second 4 pixels

  // shift right all the u32s in v1 & v2 by 17
  ushr v1.4S, v1.4S, #17
  ushr v2.4S, v2.4S, #17

  // narrow the 32-bit numbers all the way down to 8-bit numbers
  xtn v0.4H, v1.4S // v1 shrinks to the left half of v0
  xtn2 v0.8H, v2.4S // v2 shrinks to the right half of v0
  // now we've got 8 sets of 16-bit #s

  xtn v0.8B, v0.8H // back to 8 sets of 8-bit #s

  // the average pixel values are in the left half of v0--we write
  // that for red, green, and blue
  mov v1.8B, v0.8B
  mov v2.8B, v0.8B

  // ========end processing=============

  // write them back to memory
  st3 {v0.8B, v1.8B, v2.8B}, [x0]

  // advance x0
    // the left halves of v0, v1, & v2 are all 64 bits (8 bytes)
    // so we're reading 24 bytes total
    // the next address we want to read is 24 bytes from now
  add x0, x0, #24

  sub w1, w1, #8 // we just processed 8 pixels

  b.al loop

loopend: // (we've processed every pixel now--we're done!)
  ldr lr, [sp]
  add sp, sp, #16
  ret

.data
magic_number: .word 0xAAAB
