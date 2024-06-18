.global _start   // _start is a global label
_start:
  // let's capitalize the "csci" string in the .data section

  // load the address of the csci string into x0
  ldr x0, =csci // address of the csci string = addr of its first char

  // capitalize the first char
  ldrb w1, [x0] // x0 holds the addr of the 'c'
  // w1 is the right 32 bits of x1 (ldrb can only handle 32 bits)
  sub w1, w1, #32 // subtract 32 from w1 to capitalize
  strb w1, [x0] // store the capitalized char into the same addr I read from

  // go to the next char
  add x0, x0, #1 // the next char is at the next byte in memory

  // capitalize the next char
  ldrb w1, [x0] // x0 holds the addr of the next char
  sub w1, w1, #32 // subtract 32 from w1 to capitalize
  strb w1, [x0] // store the capitalized char into the same addr I read from

  // go to the next char
  add x0, x0, #1 // the next char is at the next byte in memory

  // capitalize the next char
  ldrb w1, [x0] // x0 holds the addr of the next char
  sub w1, w1, #32 // subtract 32 from w1 to capitalize
  strb w1, [x0] // store the capitalized char into the same addr I read from

  // go to the next char
  add x0, x0, #1 // the next char is at the next byte in memory

  // capitalize the next char
  ldrb w1, [x0] // x0 holds the addr of the next char
  sub w1, w1, #32 // subtract 32 from w1 to capitalize
  strb w1, [x0] // store the capitalized char into the same addr I read from

  // let's print out our csci string to stdout
  mov x8, #64 // write syscall is #64
  mov x0, #1 // file #1 is stdout
  ldr x1, =csci // addr of string goes in x1
  mov x2, #5 // # of chars to print from the string at the starting addr given in x1
  svc #0 // run the syscall I just set up

  mov x0, #0
  mov x8, #93   // move 93 into the register x8
  // 93 is the code for the "exit" system call
  svc #0  // hey Linux kernel, please execute the system call that I just set up!

.data
csci: .ascii "csci\n"
