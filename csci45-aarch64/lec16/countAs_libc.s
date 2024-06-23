.global main
.type main, %function
main:
  sub sp, sp, #32
  str lr, [sp]
  str x19, [sp, #8]
  str x20, [sp, #16]

  // open file.txt for reading
  ldr x0, =filename
  ldr x1, =mode
  bl fopen
  // x0 now holds the FILE*
  mov x19, x0

  // read the entire file, keeping track of how many 'a' chars we see
  mov w20, #0 // hold the count in x20

loop:
  // read one char at at time into nextchar
  mov x0, x19
  bl fgetc
  // if x0 != -1, then we sucessfully read another char; otherwise
  // we're at the end of the file
  cmp w0, #-1
  b.eq donereading

  // *nextchar holds the char we read
  cmp w0, #'a'
  b.ne dontadd1

  // add 1 to count
  add w20, w20, #1

dontadd1:
  // keep looping
  b.al loop

donereading:

  // close the file
  mov x0, x19
  bl fclose

  // output # of 'a's seen
  ldr x0, =fmt
  mov w1, w20
  bl printf

  // return 0
  mov w0, #0
  ldr lr, [sp]
  ldr x19, [sp, #8]
  ldr x20, [sp, #16]
  add sp, sp, #16
  ret

.data
filename: .asciz "file.txt"
mode: .asciz "r"
fmt: .asciz "Number of 'a's: %d\n"
