.global _start   // _start is a global label
_start:
  // let's print "Hello, world!" to stdout
  mov r7, #4 // write syscall is #4
  mov r0, #1 // file #1 is stdout
  ldr r1, =hello_string // addr of string goes in r1
  mov r2, #14 // # of chars to print from the string at the starting addr given in r1
  swi 0 // run the syscall I just set up

  mov r0, #0
  mov r7, #1   // move 1 into the register r7
  // 1 is the code for the "exit" system call
  swi 0  // hey Linux kernel, please execute the system call that I just set up!

.data
hello_string: .ascii "Hello, world!\n"
