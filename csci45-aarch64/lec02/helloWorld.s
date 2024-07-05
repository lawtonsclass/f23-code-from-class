.global _start   // _start is a global label
_start:
  // let's print "Hello, world!" to stdout
  mov x8, #64 // write syscall is #64
  mov w0, #1 // file #1 is stdout
  ldr x1, =hello_string // addr of string goes in x1
  mov x2, #14 // # of chars to print from the string at the starting addr given in x1
  svc #0 // run the syscall I just set up

  b.al exitLabel // "branch always"

.data

hello_string: .ascii "Hello, world!\n"
