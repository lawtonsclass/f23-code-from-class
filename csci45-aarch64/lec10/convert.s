.global convert_to_all_caps
.type convert_to_all_caps, %function
convert_to_all_caps:
  // void convert_to_all_caps(char* str);
  // str is in x0

  sub sp, sp, #16
  str lr, [sp]
  str x19, [sp, #8]

  mov x19, x0

  // while (*x19 != '\0')
loop:
  ldrb w1, [x19] 
  cmp w1, #0
  b.eq done

  // convert w1 to uppercase
  // toupper(char)
  mov w0, w1
  bl toupper

  // put that character back at *x19
  strb w0, [x19]

  // advance x19 to point to the next char
  add x19, x19, #1

  b.al loop

done:
  ldr lr, [sp]
  ldr x19, [sp, #8]
  add sp, sp, #16
  ret
