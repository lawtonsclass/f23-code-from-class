.global main
.type main, %function
.func main
main:
  push {r4-r11, lr}

  // let's get a # from the user and store it on the stack!
  // make room on the stack for 1 new int (4 bytes)
  sub sp, sp, #4
  ldr r0, =fmt
  mov r1, sp // sp by itself is the addr of our new local var!
  bl scanf

  // the top of the stack is set to whatever the user typed--let's put
  // it in r0
  pop {r0}
  cmp r0, #42
  bge ge42
lt42:
  ldr r0, =string2
  bl printf
  bal done
ge42:
  ldr r0, =string1
  bl printf
done:

  mov r0, #0
  pop {r4-r11, pc}

.data
fmt: .asciz "%d"
string1: .asciz ">= 42!\n"
string2: .asciz "< 42!\n"
