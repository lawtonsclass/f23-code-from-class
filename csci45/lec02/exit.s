.global exitLabel // now people in other files can use this label

exitLabel:
  mov r0, #0
  mov r7, #1   // move 1 into the register r7
  // 1 is the code for the "exit" system call
  swi 0  // hey Linux kernel, please execute the system call that I just set up!
