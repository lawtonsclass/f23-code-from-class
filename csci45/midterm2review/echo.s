.global main
.type main, %function
.func main
main:
  push {r4-r11, lr}

loop:
  // use getchar/putchar to echo stdin back to stdout until EOF
  bl getchar
  // r0 now holds the next char; check if it's EOF
  cmp r0, #-1
  beq done

  // if we're not done, put the char back onto stdout
  // the correct arg is already in r0!
  bl putchar
  
  // and then repeat
  bal loop


done:
  mov r0, #0
  pop {r4-r11, pc}
