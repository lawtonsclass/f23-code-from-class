.global main
.type main, %function
main:
  sub sp, sp, #16
  str lr, [sp]

  // let's get a # from the user and store it on the stack!
  // make room on the stack for 1 new int (4 bytes)
  // we have to subtract from sp in increments of 16--technically we
  // have room right now, but we'll be wasteful for fun
  sub sp, sp, #16
  ldr x0, =fmt
  mov x1, sp // sp by itself can be the addr of our new local var!
  bl scanf

  // the top of the stack is set to whatever the user typed--let's put
  // it in w0 (b/c it's an int) and clean up our stack
  ldr w0, [sp]
  add sp, sp, #16
  cmp w0, #42
  b.ge ge42
lt42:
  ldr x0, =string2
  bl printf
  b.al done
ge42:
  ldr x0, =string1
  bl printf
done:

  mov w0, #0
  ldr lr, [sp]
  add sp, sp, #16
  ret

.data
fmt: .asciz "%d"
string1: .asciz ">= 42!\n"
string2: .asciz "< 42!\n"
