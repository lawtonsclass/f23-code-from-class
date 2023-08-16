.global _start   // _start is a global label
_start:
  mov r0, #41
  mov r1, #5

  // check if r0 == 42
  cmp r0, #42
  beq truebranch // jumps to truebranch if r0 == 42; otherwise does nothing

  // if r0 != 42, we didn't branch (so we just continue executing instructions)
  // falsebranch:
  sub r1, r1, #1
  // now we're done with the false branch
  // we don't want to fall through and continue to the true branch
  bal done // go to the done label no matter what

truebranch:
  add r1, r1, #1

done:

  // exit (0)
  mov r0, #0
  mov r7, #1   // move 1 into the register r7
  // 1 is the code for the "exit" system call
  swi 0  // hey Linux kernel, please execute the system call that I just set up!

.data
