.global main
.type main, %function
.func main
main:
  push {r4-r10, lr}

  // mov 1.0 into the d0 register (as a double)
  vmov.f64 d0, #1.0
  // call atan with 1.0 as the first/only arg.
  bl atan
  // (d0 is the double equivalent of r0)
  // d0 holds pi/4

  // mov 4 into d1
  vmov.f64 d1, #4.0
  // multiply d0 by d1
  vmul.f64 d0, d0, d1
  // d0 holds pi

  // the format string is the first arg for printf, so it goes in r0
  // as usual
  ldr r0, =fmt
  // printf expects a second arg that is 8 bytes in r2-r3
  // takes d0 and splits into r2 and r3
  vmov r2, r3, d0
  bl printf

  
  // return 0
  mov r0, #0
  pop {r4-r10, pc}

.data
fmt: .asciz "%f\n"
