.global convert_to_all_caps
.type convert_to_all_caps, %function
.func convert_to_all_caps
convert_to_all_caps:
  // void convert_to_all_caps(char* str);
  // str is in r0

  push {r4-r10, lr} // stack needs to be at a multiple of 8 bytes to make futher function calls

  mov r4, r0

  // while (*r4 != '\0')
loop:
  ldrb r1, [r4] 
  cmp r1, #'\0'
  beq done

  // convert r1 to uppercase
  // toupper(char)
  mov r0, r1
  bl toupper

  // put that character back at *r4
  strb r0, [r4]

  // advance r4 to point to the next char
  add r4, r4, #1

  bal loop

done:
  pop {r4-r10, pc}
