.global main
.type main, %function
.func main
main:
  push {r4-r11, lr}

  // srand(time(0))
  mov r0, #0
  bl time
  bl srand

  // print 50 random #s
  mov r4, #0
loop:
  cmp r4, #50
  bge done

  // call rand() and print the #
  bl rand

  // printf("%d\n", rand_result)
  mov r1, r0
  ldr r0, =fmt
  bl printf

  add r4, r4, #1
  bal loop

done:
  mov r0, #0
  pop {r4-r11, pc}

.data
fmt: .asciz "%d\n"
