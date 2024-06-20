.global main
.type main, %function
main:
  sub sp, sp, #16
  str lr, [sp]
  str x19, [sp, #8]

  mov w19, #0 // start count at 0

  // repeatedly call getchar until we see EOF
loop:
  bl getchar
  // w0 holds the char the user typed
  // stop counting if it was EOF (-1)
  cmp w0, #-1
  b.eq done

  // see if x0 was a star char
  cmp w0, #'*'
  b.ne notastar

  // if it was a star, add 1 to x4
  add w19, w19, #1

notastar:

  // continue looping
  b.al loop

done:

  // print out the count
  ldr x0, =fmt
  mov w1, w19
  bl printf

  mov w0, #0
  ldr lr, [sp]
  ldr x19, [sp, #8]
  add sp, sp, #16
  ret

.data
fmt: .asciz "Number of *s: %d\n"
