.global _start   // _start is a global label
_start:
  mov x0, #41
  mov x1, #5

  // check if x0 == 42
  cmp x0, #42
  b.eq truebranch // jumps to truebranch if x0 == 42; otherwise does nothing

  // if x0 != 42, we didn't branch (so we just continue executing instructions)
  // falsebranch:
  sub x1, x1, #1
  // now we're done with the false branch
  // we don't want to fall through and continue to the true branch
  b.al done // go to the done label no matter what

truebranch:
  add x1, x1, #1

done:

  // exit (0)
  mov x0, #0
  mov x8, #93   // move 93 into the register x8
  // 1 is the code for the "exit" system call
  svc #0  // hey Linux kernel, please execute the system call that I just set up!

.data
