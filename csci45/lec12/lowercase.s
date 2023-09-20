.global main
.type main, %function
.func main
main:
  push {r4-r11, lr}

  mov r4, #0 // start count at 0

  // repeatedly call getchar until we see EOF
loop:
  bl getchar
  // r0 holds the char the user typed
  // stop counting if it was EOF (-1)
  cmp r0, #-1
  beq done

  // lowercase the char we got
  bl tolower
  // print out that lowercased char
  bl putchar

  // continue looping
  bal loop

done:

  mov r0, #0
  pop {r4-r11, pc}

.data
fmt: .asciz "Number of *s: %d\n"
