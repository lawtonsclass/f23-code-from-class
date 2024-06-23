.global main
.type main, %function
main:
  sub sp, sp, #16
  str lr, [sp]

  fmov s0, #3.5 // x1
  fmov s1, #2.5 // y1
  fmov s2, #1.5 // x2
  fmov s3, #-1.0 // y2

  // let's calculate the distance and put it into s4
  fsub s0, s2, s0 // x2 - x1
  fsub s1, s3, s1 // x2 - x1
  fabs s0, s0 // |x2 - x1|
  fabs s1, s1 // |y2 - y1|
  fmul s0, s0, s0 // |x2 - x1|^2
  fmul s1, s1, s1 // |y2 - y1|^2
  fadd s0, s0, s1 // add the squared differences
  fsqrt s4, s0

  // printf expects the first floating point argument argument in d0
  fcvt d0, s4
  fmov d8, d0 // printf will clobber d0, so save it
  // d8-d31 are saved registers
  // the format string is the first arg to printf, so it goes in x0 as usual
  ldr x0, =fmt
  bl printf

  // using d0, print "yes" or "no" if the value stored is <= 1.0
  fmov d1, #1.0
  fcmp d8, d1 // compare (saved) dist with 1.0
  b.le it_was_le
it_was_gt:
  // print it was > 1.0 
  ldr x0, =gt
  bl printf
  b.al done
it_was_le:
  ldr x0, =le
  bl printf
done:

  // return 0
  mov w0, #0
  ldr lr, [sp]
  add sp, sp, #16
  ret

.data
fmt: .asciz "%f\n"
gt: .asciz "no! > 1.0\n"
le: .asciz "yes! <= 1.0\n"
