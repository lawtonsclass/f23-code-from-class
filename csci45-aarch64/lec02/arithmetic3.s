.global _start   // _start is a global label
_start:
  // ((4×7) / 3) + 42

  // load the constant 4
  ldr x1, =four  // x1 = &four
  ldr x1, [x1] // x1 = *x1

  mov x1, #4
  mov x2, #7
  mul x0, x1, x2
  mov x3, #3
  udiv x0, x0, x3 // x0 = x0 / x3  (udiv for some reason can't take immediates)
  add x0, x0, #42

  ldr x1, =result  // x1 = &result
  str x0, [x1]     // *x1 = x0

  ldr x0, [x1]     // x0 = *x1

  mov x8, #93   // move 93 into the register x8
  // 93 is the code for the "exit" system call
  svc #0  // hey Linux kernel, please execute the system call that I just set up!

  // you can put constants down here in the code section!
  // the value can't be changed because you can't change code memory as
  // the program is running
  four: .quad 4  // .quad means a 64-bit int

.data // this is the start of the .data section
// globals go down here

result: .quad 0  // at the result label lives a 64-bit value that we can change (initially set to 0)
