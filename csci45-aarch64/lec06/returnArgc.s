.global main			     @ no more _start
.type main, %function  @ main is a function (assembler)
.func main			       @ main is a function (debugger)
main:                  @ main starts here
  // argc is in r0
  // argv is in r1

  // all we have to do is place what we want to return in r0
  // argc is already in r0
  mov r0, r0

  // when _start called main, it placed the address to return to in lr
  // to return, we just to jump there
  mov pc, lr // jump and start executing the code at the addr in lr
