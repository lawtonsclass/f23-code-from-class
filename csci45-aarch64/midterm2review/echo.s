.global main
.type main, %function
main:
  sub sp, sp, #16
  str lr, [sp]

loop:
  // use getchar/putchar to echo stdin back to stdout until EOF
  bl getchar
  // w0 now holds the next char; check if it's EOF
  cmp w0, #-1
  b.eq done

  // if we're not done, put the char back onto stdout
  // the correct arg is already in w0!
  bl putchar
  
  // and then repeat
  b.al loop


done:
  mov w0, #0
  ldr lr, [sp]
  add sp, sp, #16
  ret
