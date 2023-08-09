.global _start   // _start is a global label
_start:
  // let's print "Hello, world!" to stdout
  mov r7, #4 // write syscall is #4
  mov r0, #1 // file #1 is stdout
  ldr r1, =hello_string // addr of string goes in r1
  mov r2, #14 // # of chars to print from the string at the starting addr given in r1
  swi 0 // run the syscall I just set up

  bal exitLabel // "branch always"

.data

hello_string: .ascii "Hello, world!\n"
