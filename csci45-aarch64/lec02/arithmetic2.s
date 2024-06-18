.global _start   // _start is a global label
_start:
  // ((4×7) / 3) + 42
  mov x1, #4
  mov x2, #7
  mul x0, x1, x2
  mov x3, #3
  udiv x0, x0, x3 // x0 = x0 / x3  (udiv for some reason can't take immediates)
  add x0, x0, #42

  mov x8, #93   // move 93 into the register x8
  // 93 is the code for the "exit" system call
  svc #0  // hey Linux kernel, please execute the system call that I just set up!
