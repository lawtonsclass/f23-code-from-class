.global _start   // _start is a global label
_start:
  /* this is still a
     multi-line comment */
  mov x0, #55  // (move 55 into the register x0) x0 = 55
  mov x8, #93   // move 93 into the register x8
  // 93 is the code for the "exit" system call
  svc #0  // hey Linux kernel, please execute the system call that I just set up!

