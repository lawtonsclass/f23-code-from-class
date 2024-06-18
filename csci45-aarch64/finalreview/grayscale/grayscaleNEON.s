.global grayscaleNEON
.func grayscaleNEON
.type grayscaleNEON, %function
grayscaleNEON:
  push {r4-r11, lr}
  
  // FIXME: implement the void grayscaleNEON(char* pixelsStart, int numPixels) 
  // function to convert the colors of numPixels pixels starting at
  // pixelsStart to grayscale. numPixels is guaranteed to be a
  // multiple of 8 so that you can use 64-bit NEON registers.

  // loop through every pixel, reading a chunk at a time because NEON
loop:
  cmp r1, #0 // (we'll keep subtracting from numPixels every time we process more)
  ble loopend

  // read a chunk of pixels
  vld3.8 {d0, d1, d2}, [r0]

  // process them (convert to grayscale)
  // ========begin processing===========

  // Extend d0, d1, & d2 into q registers (converting all the values
  // to 16-bit). We have to do this so that we can add up the RGB
  // values and not lose any information to overflow.
  vmovl.u8 q2, d0
  vmovl.u8 q3, d1
  vmovl.u8 q4, d2

  // Add up the RGB values
  vadd.u16 q2, q2, q3
  vadd.u16 q2, q2, q4
  // now we need to divide them by 3

  // Get the magic constant into each 16-bit slot of a d register
  ldr r4, =magic_number
  ldr r4, [r4]
  vdup.u16 d0, r4 // dup for duplicate

  // multiply the sum in q2 by the magic constant
  // q2 is d4 & d5
  // we have to use d registers so we can extend the multiplication to
  // q registers
  // vmull is vmul e*long*ated
  vmull.u16 q3, d4, d0
  vmull.u16 q4, d5, d0
  // shift right all the u32s in q3 & q4 by 17
  vshr.u32 q3, #17
  vshr.u32 q4, #17

  // narrow the 32-bit numbers all the way down to 8-bit numbers
  vmovn.u32 d0, q3
  vmovn.u32 d1, q4
  // d0 & d1 now hold 4 16-bit numbers each. That means q0 holds 8
  // 16-bit numbers. We need to narrow once more to fit in a single d
  // register.
  vmovn.u16 d0, q0

  // the average pixel values are in d0--we write that for red, green,
  // and blue
  vmov d1, d0
  vmov d2, d0

  // ========end processing=============

  // write them back to memory
  vst3.8 {d0, d1, d2}, [r0] // (put an ! at the end to automatically advance r0)

  // advance r0
    // d0, d1, & d2 are all 64 bits (8 bytes)
    // so we're reading 24 bytes total
    // the next address we want to read is 24 bytes from now
  add r0, r0, #24

  sub r1, r1, #8 // we just processed 8 pixels

  bal loop

loopend: // (we've processed every pixel now--we're done!)
  pop {r4-r11, pc}

.data
magic_number: .word 0xAAAB
