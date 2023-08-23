.global main			     @ no more _start
.type main, %function  @ main is a function (assembler)
.func main			       @ main is a function (debugger)
main:                  @ main starts here
  // lr holds the to haddr to return to
  push {r4-r11, lr}

  // get the current pid using syscall #20
  mov r7, #20
  swi 0
  // now the pid is in r0

  // let's print the pid
  // printf(&printint, pid_num)
  mov r1, r0
  ldr r0, =printint
  // call printf
  bl printf

  // return 0
  mov r0, #0

  // return from main
  pop {r4-r11, pc} // takes the old lr that we save, and it puts it into pc

.data
printint: .asciz "%u\n" // makes a C-string for us!
