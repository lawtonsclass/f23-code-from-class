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

  // see if r0 was a star char
  cmp r0, #'*'
  bne notastar

  // if it was a star, add 1 to r4
  add r4, r4, #1

notastar:

  // continue looping
  bal loop

done:

  // print out the count
  ldr r0, =fmt
  mov r1, r4
  bl printf

  mov r0, #0
  pop {r4-r11, pc}

.data
fmt: .asciz "Number of *s: %d\n"
