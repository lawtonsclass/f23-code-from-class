.global sum10
.type sum10, %function
sum10: // int sum10(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
  // first 8 args are in x0-x7 (in our case, w0-w7)
  // rest are on the stack in reverse order
  add w0, w0, w1 
  add w0, w0, w2 
  add w0, w0, w3 
  add w0, w0, w4
  add w0, w0, w5
  add w0, w0, w6
  add w0, w0, w7

  // i is on the top of the stack (it's what sp is pointing to right now)
  ldr w1, [sp]
  add w0, w0, w1

  // j is right below i on the stack (but 8 bytes away for silly
  // alignment reasons)
  ldr w1, [sp, #8]
  add w0, w0, w1

  // result goes in w0 (and it's already there!)
  // return by putting our lr into pc
  ret
