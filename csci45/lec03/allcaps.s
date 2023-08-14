.global _start   // _start is a global label
_start:
  // let's capitalize the "csci" string in the .data section

  // load the address of the csci string into r0
  ldr r0, =csci // address of the csci string = addr of its first char

  // capitalize the first char
  ldrb r1, [r0] // r0 holds the addr of the 'c'
  sub r1, r1, #32 // subtract 32 from r1 to capitalize
  strb r1, [r0] // store the capitalized char into the same addr I read from

  // go to the next char
  add r0, r0, #1 // the next char is at the next byte in memory

  // capitalize the next char
  ldrb r1, [r0] // r0 holds the addr of the next char
  sub r1, r1, #32 // subtract 32 from r1 to capitalize
  strb r1, [r0] // store the capitalized char into the same addr I read from

  // go to the next char
  add r0, r0, #1 // the next char is at the next byte in memory

  // capitalize the next char
  ldrb r1, [r0] // r0 holds the addr of the next char
  sub r1, r1, #32 // subtract 32 from r1 to capitalize
  strb r1, [r0] // store the capitalized char into the same addr I read from

  // go to the next char
  add r0, r0, #1 // the next char is at the next byte in memory

  // capitalize the next char
  ldrb r1, [r0] // r0 holds the addr of the next char
  sub r1, r1, #32 // subtract 32 from r1 to capitalize
  strb r1, [r0] // store the capitalized char into the same addr I read from

  // let's print out our csci string to stdout
  mov r7, #4 // write syscall is #4
  mov r0, #1 // file #1 is stdout
  ldr r1, =csci // addr of string goes in r1
  mov r2, #5 // # of chars to print from the string at the starting addr given in r1
  swi 0 // run the syscall I just set up

  mov r0, #0
  mov r7, #1   // move 1 into the register r7
  // 1 is the code for the "exit" system call
  swi 0  // hey Linux kernel, please execute the system call that I just set up!

.data
csci: .ascii "csci\n"
