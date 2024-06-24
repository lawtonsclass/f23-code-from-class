.global toupper_asm
.type toupper_asm, %function
toupper_asm: // char toupper_asm(char c);
  sub sp, sp, #16
  str lr, [sp]

  cmp w0, #97
  b.lt donttouchthischar
  cmp w0, #122
  b.gt donttouchthischar
  // if we're still here, we're within the valid range!
  sub w0, w0, #32

donttouchthischar:
  ldr lr, [sp]
  add sp, sp, #16
  ret

.global main
.type main, %function
main:
  sub sp, sp, #16
  str lr, [sp]

  bl getchar 
  bl toupper_asm
  bl putchar
  mov w0, #'\n'
  bl putchar

  mov w0, #0
  ldr lr, [sp]
  add sp, sp, #16
  ret
