.global _start   // _start is a global label
_start:
  mov r0, #21

  // extract bit 2
  mov r1, #4
  and r2, r0, r1
  // check if r2 == 0, ...

  // set bit 5
  mov r1, #32
  orr r3, r0, r1

  // negate using two's complement
  mvn r4, r0 // (move negated)
  add r4, r4, #1

  // exit with return code of 0
  mov r0, #0
  mov r7, #1   // move 1 into the register r7
  // 1 is the code for the "exit" system call
  swi 0  // hey Linux kernel, please execute the system call that I just set up!

