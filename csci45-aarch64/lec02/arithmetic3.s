.global _start   // _start is a global label
_start:
  // ((4×7) / 3) + 42

  // load the constant 4
  ldr x1, =four  // x1 = &four
  ldr w1, [x1] // w1 = *x1

  mov w1, #4
  mov w2, #7
  mul w0, w1, w2
  mov w3, #3
  udiv w0, w0, w3 // w0 = w0 / w3  (udiv for some reason can't take immediates)
  add w0, w0, #42

  ldr x1, =result  // x1 = &result
  str w0, [x1]     // *x1 = x0

  ldr w0, [x1]     // x0 = *x1

  mov x8, #93   // move 93 into the register x8
  // 93 is the code for the "exit" system call
  svc #0  // hey Linux kernel, please execute the system call that I just set up!

  // you can put constants down here in the code section!
  // the value can't be changed because you can't change code memory as
  // the program is running
  four: .word 4  // .word means a 32-bit int (.quad means a 64-bit int)

.data // this is the start of the .data section
// globals go down here

result: .word 0  // at the result label lives a 32-bit value that we can change (initially set to 0)
