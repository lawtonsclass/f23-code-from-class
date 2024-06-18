.global _start   // _start is a global label
_start:
  mov x0, #87 // x0 = 87
  mov x1, #25
  mov x5, #2
  mov x2, #7
  mov x3, #3

  add x6, x0, x1  // x6 = x0 + x1
  mul x4, x6, x5  // x4 = x6 * x5
  sub x2, x2, x3  // x2 = x2 - x3
  udiv x4, x4, x2 // x4 = x4 / x2 (unsigned)

  mov x0, x4  // move the value to return into x0
  mov x8, #93   // move 1 into the register x8
  // 93 is the code for the "exit" system call
  svc #0  // hey Linux kernel, please execute the system call that I just set up!
