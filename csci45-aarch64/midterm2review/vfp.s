// Future Lawton, compile with: gcc -mfpu=neon vfp.s -o vfp

.global main
.type main, %function
.func main
main:
  push {r4-r10, lr}

  ldr r0, =scanf_fmt
  ldr r1, =num_from_user
  bl scanf // scanf("%lf", &num_from_user)

  ldr r1, =num_from_user
  vldr d0, [r1]
  vmov.f64 d1, #2.0
  ldr r1, =pi
  vldr d2, [r1]
  vmul.f64 d0, d0, d1 // d0 = 2 * d0
  vmul.f64 d0, d0, d2 // d0 = pi * d0

  // the format string is the first arg for printf, so it goes in r0
  // as usual
  ldr r0, =fmt
  // printf expects a second arg that is 8 bytes in r2-r3
  // takes d0 and splits into r2 and r3
  vmov r2, r3, d0
  bl printf

  // return 0
  mov r0, #0
  pop {r4-r10, pc} // this jumps to the return address of main

.data
fmt: .asciz "%f\n"
scanf_fmt: .asciz "%lf"
num_from_user: .double 0.0
pi: .double 3.1416
