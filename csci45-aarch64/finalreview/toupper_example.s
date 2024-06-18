.global toupper_asm
.type toupper_asm, %function
.func toupper_asm
toupper_asm: // char toupper_asm(char c);
  push {r4-r11, lr}

  cmp r0, #97
  blt donttouchthischar
  cmp r0, #122
  bgt donttouchthischar
  // if we're still here, we're within the valid range!
  sub r0, r0, #32

donttouchthischar:
  pop {r4-r11, pc}
.endfunc

.global main
.type main, %function
.func main
main:
  push {r4-r11, lr}

  bl getchar 
  bl toupper_asm
  bl putchar
  mov r0, #'\n'
  bl putchar

  mov r0, #0
  pop {r4-r11, pc}
