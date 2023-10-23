.global main
.type main, %function
.func main
main:
  push {r4-r11, lr}

  // open the file with fopen
  ldr r0, =filename
  ldr r1, =mode
  bl fopen // fopen returns a FILE*
  mov r4, r0 // save the file in r4

loop:
  // use fgetc to read one char of the file
  mov r0, r4
  bl fgetc
  // now we have the next char in r0

  // watch out for EOF
  cmp r0, #-1
  beq done

  // convert the char to uppercase and print it out
  // the character is already in r0!
  bl toupper
  bl putchar

  // repeat
  bal loop

done:
  // close the file with fclose
  mov r0, r4
  bl fclose

  mov r0, #0
  pop {r4-r11, pc}

.data
filename: .asciz "sample_file.txt"
mode: .asciz "r"
