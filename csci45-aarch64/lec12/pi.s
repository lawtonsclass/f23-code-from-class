.global main
.type main, %function
main:
  sub sp, sp, #16
  str lr, [sp]

  // mov 1.0 into the d0 register (as a double)
  fmov d0, #1.0
  // call atan with 1.0 as the first/only arg.
  bl atan
  // (d0 is the double equivalent of x0)
  // d0 holds pi/4

  // mov 4 into d1
  fmov d1, #4.0
  // multiply d0 by d1
  fmul d0, d0, d1
  // d0 holds pi

  // the format string is the first arg for printf, so it goes in x0
  // as usual
  ldr x0, =fmt
  // printf expects the double arg in d0, and it's already there
  bl printf

  
  // return 0
  mov w0, #0
  ldr lr, [sp]
  add sp, sp, #16
  ret

.data
fmt: .asciz "%f\n"
