.global main
.type main, %function
.func main
main:
  push {r4-r11, lr}

  ldr r0, =str
  // load 8-bit data in order into d0 (d0 can fit 8 8-bit things)
  vld1.8 {d0}, [r0]

  ldr r1, =offsets
  // a bunch of 32s!
  vld1.8 {d1}, [r1]

  vsub.u8 d0, d0, d1

  // store back the updated string
  vst1.8 {d0}, [r0]

  // print out the new str!
  ldr r0, =str
  bl printf

  mov r0, #0
  pop {r4-r11, pc}

.data
str: .asciz "abcdefgh\n"
offsets: .byte 32, 32, 32, 32, 32, 32, 32, 32
