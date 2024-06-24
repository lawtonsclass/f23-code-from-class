.global find
.type find, %function
find: // int find(const char* s, char c);
  sub sp, sp, #16
  str lr, [sp]
  str x19, [sp, #8]

  // s is in x0, c is in w1

  mov w2, #0 // index in s where we found c

loop:
  ldrb w3, [x0] // x0 holds the addr. of the next char to read
  cmp w3, w1
  b.eq returnIndex
  // watch out for the end of the string
  cmp w3, #0 // '\0'
  b.eq returnNegative1

  // advance index & ptr into the string (w2 & x0)
  add w2, w2, #1
  add x0, x0, #1
  b.al loop

returnIndex:
  mov w0, w2
  b.al done

returnNegative1:
  mov w0, #-1

done:
  ldr lr, [sp]
  ldr x19, [sp, #8]
  add sp, sp, #16
  ret

.data
