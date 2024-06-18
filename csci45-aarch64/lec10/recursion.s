.global fact
.type fact, %function
.func fact
fact:
  // int fact(int n);
  push {r4-r11, lr}

  cmp r0, #0 
  bne recursivecase_fact

  // base case
  mov r0, #1
  bal end_fact

recursivecase_fact:
  mov r4, r0 // r4 = n
  sub r0, r0, #1 // r0 = n-1
  bl fact // r0 = (n-1)!
  mul r0, r0, r4 // r0 = n * (n-1)!

end_fact:
  pop {r4-r11, pc}

.endfunc

.global fib
.type fib, %function
.func fib
fib:
  // int fib(int n);
  push {r4-r11, lr}

  // see if n == 0 (first base case)
  cmp r0, #0
  bne check_second_base_case

  bal end_fib 
check_second_base_case:
  // see if n == 1 (second base case)
  cmp r0, #1
  bne recursivecase_fib

  bal end_fib 
recursivecase_fib:
  mov r4, r0 // save n away
  mov r5, #0 // we'll put the sum of the recursive calls here

  sub r0, r4, #1 // r0 = n-1
  bl fib // r0 = fib(n-1)
  add r5, r5, r0

  sub r0, r4, #2 // r0 = n-2
  bl fib // r0 = fib(n-2)
  add r5, r5, r0

  // r0 = answer
  mov r0, r5

end_fib:
  pop {r4-r11, pc}
