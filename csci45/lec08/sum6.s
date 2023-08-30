.global sum6
.type sum6, %function
.func sum6
sum6: // int sum6(int a, int b, int c, int d, int e, int f);
  // first 4 args are in r0-r3
  // rest are on the stack
  add r0, r0, r1 
  add r0, r0, r2 
  add r0, r0, r3 

  // e is on the top of the stack (it's what sp is pointing to right now)
  ldr r1, [sp]
  add r0, r0, r1

  // f is right below e on the stack
  ldr r1, [sp, #4]
  add r0, r0, r1

  // result goes in r0 (and it's already there!)
  // return by putting our lr into pc
  mov pc, lr
