.global _start   // _start is a global label
_start:
  @ this is also a single-line comment
  /* this */
  mov r0, #55  // (move 55 into the register r0) r0 = 55
  mov r7, #1   // move 1 into the register r7
  // 1 is the code for the "exit" system call
  swi 0  // hey Linux kernel, please execute the system call that I just set up!

