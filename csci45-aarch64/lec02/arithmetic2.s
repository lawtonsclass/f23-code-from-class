.global _start   // _start is a global label
_start:
  // ((4×7) / 3) + 42
  mov w1, #4
  mov w2, #7
  mul w0, w1, w2
  mov w3, #3
  udiv w0, w0, w3 // w0 = w0 / w3  (udiv for some reason can't take immediates)
  add w0, w0, #42

  mov x8, #93   // move 93 into the register x8
  // 93 is the code for the "exit" system call
  svc #0  // hey Linux kernel, please execute the system call that I just set up!
