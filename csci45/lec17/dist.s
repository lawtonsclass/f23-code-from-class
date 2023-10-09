.global main
.type main, %function
.func main
main:
  push {r4-r10, lr} // can't do r4-r11 because I need the stack aligned to an 8-byte offset

  vmov.f32 s0, #3.5 // x1
  vmov.f32 s1, #2.5 // y1
  vmov.f32 s2, #1.5 // x2
  vmov.f32 s3, #-1.0 // y2

  // let's calculate the distance and put it into s4
  vsub.f32 s0, s2, s0 // x2 - x1
  vsub.f32 s1, s3, s1 // x2 - x1
  vabs.f32 s0, s0 // |x2 - x1|
  vabs.f32 s1, s1 // |y2 - y1|
  vmul.f32 s0, s0, s0 // |x2 - x1|^2
  vmul.f32 s1, s1, s1 // |y2 - y1|^2
  vadd.f32 s0, s0, s1 // add the squared differences
  vsqrt.f32 s4, s0

  vcvt.f64.f32 d0, s4
  // the format string is the first arg to printf, so it goes in r0 as usual
  ldr r0, =fmt
  // printf expects a second argument (if it's 8 bytes) r2-r3
  vmov r2, r3, d0
  // remember to align the stack to a multiple of 8 bytes!!!
  bl printf

  // using d0, print "yes" or "no" if the value stored is <= 1.0
  vmov.f64 d1, #1.0
  vcmp.f64 d0, d1 // compare dist with 1.0
  vmrs APSR_nzcv, FPSCR // bring over the flags from the FPU!
  ble it_was_le
it_was_gt:
  // print it was > 1.0 
  ldr r0, =gt
  bl printf
  bal done
it_was_le:
  ldr r0, =le
  bl printf
done:

  // return 0
  mov r0, #0
  pop {r4-r10, pc}

.data
fmt: .asciz "%f\n"
gt: .asciz "no! > 1.0\n"
le: .asciz "yes! <= 1.0\n"
