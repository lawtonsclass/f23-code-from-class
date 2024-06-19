.global main
.type main, %function
.func main
main:
  sub sp, sp, #16
  str lr, [sp]

  // call sum10 and print out the result
  mov w0, #1
  mov w1, #2
  mov w2, #3
  mov w3, #4
  mov w4, #5
  mov w5, #6
  mov w6, #7
  mov w7, #8

  // add the last 2 args on the stack in reverse order, taking up 8
  // bytes per push
  sub sp, sp, #16
  mov w8, #9
  str w8, [sp]
  mov w8, #10
  str w8, [sp, #8]

  bl sum10
  // answer is in w0
  // clean up the stack
  add sp, sp, #16

  mov w1, w0
  ldr x0, =fmt
  bl printf

  mov w0, #0
  ldr lr, [sp]
  add sp, sp, #16
  ret

.data
fmt: .asciz "%d\n"
