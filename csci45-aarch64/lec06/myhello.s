.global main			     // no more _start
.type main, %function  // main is a function (assembler)
main:                  // main starts here
  // lr (x30) holds the addr for main to return to; we need to save it
  // if we want to call other functions
  sub sp, sp, #16 // make room on the stack for 16 bytes (always must be a multiple of 16!!!)
  // now there's room at [sp] and [sp, #8]--we can put lr at either spot
  str lr, [sp]

  // put the addr of the C-string to print in x0
  ldr x0, =hellostring
  bl printf // this implicitly sets lr to be the addr of the next instruction in main

  // return 0 (ints are 32 bits, so we use w0)
  mov w0, #0

  // return from main
  ldr lr, [sp] // restore lr
  add sp, sp, #16 // reset the stack
  ret // jumps to the addr stored in lr

.data
hellostring: .asciz "Hello, world!\n" // makes a C-string for us!
