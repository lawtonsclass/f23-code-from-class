.global exitLabel // now people in other files can use this label

exitLabel:
  mov x0, #0
  mov x8, #93   // move 93 into the register x8
  // 93 is the code for the "exit" system call
  svc #0  // hey Linux kernel, please execute the system call that I just set up!
