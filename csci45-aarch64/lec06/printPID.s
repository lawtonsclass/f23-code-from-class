.global main			     // no more _start
.type main, %function  // main is a function (assembler)
main:                  // main starts here
  // lr (x30) holds the addr for main to return to; we need to save it
  // if we want to call other functions
  sub sp, sp, #16 // make room on the stack for 16 bytes (always must be a multiple of 16!!!)
  // now there's room at [sp] and [sp, #8]--we can put lr at either spot
  str lr, [sp]

  // get the current pid using syscall #172
  mov x8, #172
  svc #0
  // now the pid is in x0

  // let's print the pid
  // printf(&printint, pid_num)
  mov x1, x0
  ldr x0, =printint
  // call printf
  bl printf

  // return 0
  mov w0, #0

  // return from main
  ldr lr, [sp] // restore lr
  add sp, sp, #16 // reset the stack
  ret // jumps to the addr stored in lr

.data
printint: .asciz "%u\n" // makes a C-string for us!
