.global factorial
.type factorial, %function
factorial: // int factorial(int n);
  sub sp, sp, #16
  str lr, [sp]
  str x19, [sp, #8]

  // n is in w0

  cmp w0, #0
  b.eq baseCase
  b.ne recursiveCase

baseCase:
  mov w0, #1
  b.al done

recursiveCase:
  // n * factorial(n-1) 
  mov w19, w0
  sub w0, w0, #1 // w0 holds n-1 now
  bl factorial // now w0 holds factorial(n-1)
  mul w0, w0, w19

done:
  ldr lr, [sp]
  ldr x19, [sp, #8]
  add sp, sp, #16
  ret

.data
