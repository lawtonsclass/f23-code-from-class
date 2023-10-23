.global find
.type find, %function
.func find
find: // int find(const char* s, char c);
  push {r4-r11, lr} 

  // s is in r0, c is in r1

  mov r2, #0 // index in s where we found c

loop:
  ldrb r3, [r0] // r0 holds the addr. of the next char to read
  cmp r3, r1
  beq returnIndex
  // watch out for the end of the string
  cmp r3, #0 // '\0'
  beq returnNegative1

  // advance index & ptr into the string (r2 & r0)
  add r2, r2, #1
  add r0, r0, #1
  bal loop

returnIndex:
  mov r0, r2
  bal done

returnNegative1:
  mov r0, #-1

done:
  pop {r4-r11, pc}

.data
