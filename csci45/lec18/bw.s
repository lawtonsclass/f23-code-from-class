.global bwNEON
.func bwNEON
.type bwNEON, %function
bwNEON:
  push {r4-r11, lr}
  
  // FIXME: implement the void bwNEON(char* pixelsStart, int numPixels)
  // function to convert numPixels pixels to b&w starting at pixelsStart. 
  // numPixels is guaranteed to be a multiple of 8 so that you can use
  // 64-bit NEON registers.

loop:
  cmp r1, #0 // (we'll keep subtracting from numPixels (r1) every time we process more)
  ble done

  // read a chunk of pixels
  vld3.8 {d0, d1, d2}, [r0]

  // process them
  vmovl.u8 q2, d0
  vmovl.u8 q3, d1
  vmovl.u8 q4, d2
  vadd.u16 q2, q2, q3
  vadd.u16 q2, q2, q4 // q2 = original q2 + q3 + q4

  // put 384 into q5 (copied into every 16-bit chunk)
  vmov.u16 q5, #0
  vmov.u16 q6, #128
  vadd.u16 q5, q5, q6
  vadd.u16 q5, q5, q6
  vadd.u16 q5, q5, q6 // now q5 holds 384
  vcge.u16 q2, q2, q5 // compare r+g+b with the threshold value

  // shink q2 down into 8 bits again
  vmovn.i16 d0, q2 // d0 holds red
  vmovn.i16 d1, q2 // d1 holds green
  vmovn.i16 d2, q2 // d2 holds blue

  // write them back to memory
  vst3.8 {d0, d1, d2}, [r0] // (put an ! at the end to automatically advance r0)

  // advance r0
    // d0, d1, & d2 are all 64 bits (8 bytes)
    // so we're reading 24 bytes total
    // the next address we want to read from is 24 bytes from now
  add r0, r0, #24

  // we just processed 8 pixels
  sub r1, r1, #8
  bal loop
done:

  pop {r4-r11, pc}

