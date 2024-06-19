.global _start   // _start is a global label
_start:
  mov x0, #21

  // extract bit 2
  mov x1, #4
  and x2, x0, x1
  // check if x2 == 0, ...

  // set bit 5
  mov x1, #32
  orr x3, x0, x1

  // negate using two's complement
  mvn x4, x0 // (move negated)
  add x4, x4, #1

  // exit with return code of 0
  mov x0, #0
  mov x8, #93   // move 93 into the register x8
  // 93 is the code for the "exit" system call
  svc #0  // hey Linux kernel, please execute the system call that I just set up!

