.global main
.type main, %function
main:
  sub sp, sp, #32
  str lr, [sp]
  str x19, [sp, #8]
  str x20, [sp, #16]

  // open file.txt for reading
  mov x8, #56 // the # of the openat syscall
  mov w0, #-100 // -100 stands for AT_FDCWD (open relative to current working directory)
  ldr x1, =filename
  mov w2, #0 // 0 is for read-only
  svc #0
  // w0 now holds the file descriptor for file.txt
  mov w19, w0

  // read the entire file, keeping track of how many 'a' chars we see
  mov w20, #0 // hold the count in w20

loop:
  // read one char at at time into nextchar
  mov x8, #63
  mov w0, w19
  ldr x1, =nextchar
  mov x2, #1
  svc #0 
  // if x0 > 0, then we sucessfully read another char; otherwise we're
  // probably at the end of the file
  cmp x0, #0
  b.le donereading

  // *nextchar holds the char we read
  ldr x0, =nextchar
  ldrb w0, [x0] // x0 holds the char (x0 = *nextchar)
  cmp w0, #'a'
  bne dontadd1

  // add 1 to count
  add w20, w20, #1

dontadd1:
  // keep looping
  b.al loop

donereading:

  // close the file
  mov x8, #57
  mov w0, w19
  svc #0

  // output # of 'a's seen
  ldr x0, =fmt
  mov w1, w20
  bl printf

  // return 0
  mov w0, #0
  ldr lr, [sp]
  ldr x19, [sp, #8]
  ldr x20, [sp, #16]
  add sp, sp, #32
  ret

.data
filename: .asciz "file.txt"
nextchar: .ascii "X"
fmt: .asciz "Number of 'a's: %d\n"
