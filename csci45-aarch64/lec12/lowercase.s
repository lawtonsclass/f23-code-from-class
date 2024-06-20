.global main
.type main, %function
main:
  sub sp, sp, #16
  str lr, [sp]

  // repeatedly call getchar until we see EOF
loop:
  bl getchar
  // w0 holds the char the user typed
  // stop counting if it was EOF (-1)
  cmp w0, #-1
  b.eq done

  // lowercase the char we got
  bl tolower
  // print out that lowercased char
  bl putchar

  // continue looping
  b.al loop

done:

  mov w0, #0
  ldr lr, [sp]
  add sp, sp, #16
  ret

.data
fmt: .asciz "Number of *s: %d\n"
