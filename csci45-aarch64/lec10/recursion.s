.global fact
.type fact, %function
fact:
  // int fact(int n);
  sub sp, sp, #16
  str lr, [sp]
  str x19, [sp, #8]

  cmp w0, #0 
  b.ne recursivecase_fact

  // base case
  mov w0, #1
  b.al end_fact

recursivecase_fact:
  mov w19, w0 // w19 = n
  sub w0, w0, #1 // w0 = n-1
  bl fact // x0 = (n-1)!
  mul w0, w0, w19 // w0 = n * (n-1)!

end_fact:
  ldr lr, [sp]
  ldr x19, [sp, #8]
  add sp, sp, #16
  ret

.global fib
.type fib, %function
fib:
  // int fib(int n);
  sub sp, sp, #32
  str lr, [sp]
  str x19, [sp, #8]
  str x20, [sp, #16]

  // see if n == 0 (first base case)
  cmp w0, #0
  b.ne check_second_base_case

  b.al end_fib 
check_second_base_case:
  // see if n == 1 (second base case)
  cmp w0, #1
  b.ne recursivecase_fib

  b.al end_fib 
recursivecase_fib:
  mov w19, w0 // save n away
  mov w20, #0 // we'll put the sum of the recursive calls here

  sub w0, w19, #1 // w0 = n-1
  bl fib // w0 = fib(n-1)
  add w20, w20, w0

  sub w0, w19, #2 // w0 = n-2
  bl fib // w0 = fib(n-2)
  add w20, w20, w0

  // w0 = answer
  mov w0, w20

end_fib:
  ldr lr, [sp]
  ldr x19, [sp, #8]
  ldr x20, [sp, #16]
  add sp, sp, #32
  ret
