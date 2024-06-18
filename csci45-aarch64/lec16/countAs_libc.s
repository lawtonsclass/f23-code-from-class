.global main
.type main, %function
.func main
main:
  push {r4-r11, lr}

  // open file.txt for reading
  ldr r0, =filename
  ldr r1, =mode
  bl fopen
  // r0 now holds the FILE*
  mov r4, r0

  // read the entire file, keeping track of how many 'a' chars we see
  mov r5, #0 // hold the count in r5

loop:
  // read one char at at time into nextchar
  mov r0, r4
  bl fgetc
  // if r0 != -1, then we sucessfully read another char; otherwise
  // we're at the end of the file
  cmp r0, #-1
  beq donereading

  // *nextchar holds the char we read
  cmp r0, #'a'
  bne dontadd1

  // add 1 to count
  add r5, r5, #1

dontadd1:
  // keep looping
  bal loop

donereading:

  // close the file
  mov r0, r4
  bl fclose

  // output # of 'a's seen
  ldr r0, =fmt
  mov r1, r5
  bl printf

  // return 0
  mov r0, #0
  pop {r4-r11, pc}

.data
filename: .asciz "file.txt"
mode: .asciz "r"
fmt: .asciz "Number of 'a's: %d\n"
