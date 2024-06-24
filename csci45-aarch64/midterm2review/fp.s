// Future Lawton, compile with: gcc -mfpu=neon vfp.s -o vfp

.global main
.type main, %function
main:
  sub sp, sp, #16
  str lr, [sp]

  ldr x0, =scanf_fmt
  ldr x1, =num_from_user
  bl scanf // scanf("%lf", &num_from_user)

  ldr x1, =num_from_user
  ldr d0, [x1]
  fmov d1, #2.0
  ldr x1, =pi
  ldr d2, [x1]
  fmul d0, d0, d1 // d0 = 2 * d0
  fmul d0, d0, d2 // d0 = pi * d0

  // the format string is the first arg for printf, so it goes in x0
  // as usual
  ldr x0, =fmt
  // printf expects the second double arg in d0, and it's already there
  bl printf

  // return 0
  mov w0, #0
  ldr lr, [sp]
  add sp, sp, #16
  ret

.data
fmt: .asciz "%f\n"
scanf_fmt: .asciz "%lf"
num_from_user: .double 0.0
pi: .double 3.1416
