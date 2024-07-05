.global _start   // _start is a global label
_start:
  mov w0, #87 // w0 = 87
  mov w1, #25
  mov w5, #2
  mov w2, #7
  mov w3, #3

  add w6, w0, w1  // w6 = w0 + w1
  mul w4, w6, w5  // w4 = w6 * w5
  sub w2, w2, w3  // w2 = w2 - w3
  udiv w4, w4, w2 // w4 = w4 / w2 (unsigned)

  mov w0, w4  // move the value to return into w0
  mov x8, #93   // move 1 into the register x8
  // 93 is the code for the "exit" system call
  svc #0  // hey Linux kernel, please execute the system call that I just set up!
