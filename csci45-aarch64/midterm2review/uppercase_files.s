.global main
.type main, %function
main:
  sub sp, sp, #16
  str lr, [sp]
  str x19, [sp, #8]

  // open the file with fopen
  ldr x0, =filename
  ldr x1, =mode
  bl fopen // fopen returns a FILE*
  mov x19, x0 // save the file in x19 

loop:
  // use fgetc to read one char of the file
  mov x0, x19
  bl fgetc
  // now we have the next char in w0

  // watch out for EOF
  cmp w0, #-1
  b.eq done

  // convert the char to uppercase and print it out
  // the character is already in w0!
  bl toupper
  bl putchar

  // repeat
  b.al loop

done:
  // close the file with fclose
  mov x0, x19
  bl fclose

  mov w0, #0
  ldr lr, [sp]
  ldr x19, [sp, #8]
  add sp, sp, #16
  ret

.data
filename: .asciz "sample_file.txt"
mode: .asciz "r"
