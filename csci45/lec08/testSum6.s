.global main
.type main, %function
.func main
main:
  push {r4-r11, lr}

  // call sum6 and print out the result
  mov r0, #1
  mov r1, #2
  mov r2, #3
  mov r3, #4

  // add the last 2 args on the stack in reverse order
  mov r4, #6
  push {r4}
  mov r4, #5
  push {r4}

  bl sum6
  // answer is in r0
  // clean up the stack
  add sp, sp, #8

  mov r1, r0
  ldr r0, =fmt
  bl printf

  mov r0, #0
  pop {r4-r11, pc}

.data
fmt: .asciz "%d\n"
