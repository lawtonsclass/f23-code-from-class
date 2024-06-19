.global main			     // no more _start
.type main, %function  // main is a function (assembler)
main:                  // main starts here
  // argc is in w0 (b/c it's an int, and ints are 32 bits)
  // argv is in x1 (b/c it's a pointer, and pointers are 64 bits)

  // all we have to do is place what we want to return in w0
  // argc is already in w0
  mov w0, w0

  // when _start called main, it placed the address to return to in lr
  // to return, we just to jump there
  ret // jump and start executing the code at the addr in lr
