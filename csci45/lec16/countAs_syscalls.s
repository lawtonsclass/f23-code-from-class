.global main
.type main, %function
.func main
main:
  push {r4-r11, lr}

  // open file.txt for reading
  mov r7, #5 // the # of the open syscall
  ldr r0, =filename
  mov r1, #0 // 0 is for read-only
  swi 0
  // r0 now holds the file descriptor for file.txt
  mov r4, r0

  // read the entire file, keeping track of how many 'a' chars we see
  mov r5, #0 // hold the count in r5

loop:
  // read one char at at time into nextchar
  mov r7, #3
  mov r0, r4
  ldr r1, =nextchar
  mov r2, #1
  swi 0
  // if r0 > 0, then we sucessfully read another char; otherwise we're
  // probably at the end of the file
  cmp r0, #0
  ble donereading

  // *nextchar holds the char we read
  ldr r0, =nextchar
  ldrb r0, [r0] // r0 holds the char (r0 = *nextchar)
  cmp r0, #'a'
  bne dontadd1

  // add 1 to count
  add r5, r5, #1

dontadd1:
  // keep looping
  bal loop

donereading:

  // close the file
  mov r7, #6
  mov r0, r4
  swi 0

  // output # of 'a's seen
  ldr r0, =fmt
  mov r1, r5
  bl printf

  // return 0
  mov r0, #0
  pop {r4-r11, pc}

.data
filename: .asciz "file.txt"
nextchar: .ascii "X"
fmt: .asciz "Number of 'a's: %d\n"
