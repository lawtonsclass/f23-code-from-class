.global guessTheNumberGame
.type guessTheNumberGame, %function
guessTheNumberGame:
  // void guessTheNumberGame(int up_to);
  // up_to is in w0

  sub sp, sp, #32
  str lr, [sp]
  str x19, [sp, #8]
  str x20, [sp, #16]

  /*
  void guessTheNumberGame(int up_to) {
    // pick random # from 1 to up_to
    int n = getRandomNumberFrom1To(up_to);

    int guess = -1;
    while (guess != n) {
      printf("Enter your guess: ");
      scanf("%d", &guess);

      if (guess < n) {
        printf("Too low\n");
      } else if (guess > n) {
        printf("Too high\n");
      } else {
        printf("You got it!\n");
      }
    }
  }
  */

  // up_to is already in x0
  bl getRandomNumberFrom1To
  mov w19, w0 // save n in a saved register

  mov w20, #-1
loop:
  cmp w20, w19
  b.eq done
  
  // loop body
  ldr x0, =enterguess
  bl printf

  ldr x0, =scanffmt
  ldr x1, =theguess
  bl scanf
  // mov theguess into x20
  ldr x20, =theguess // 64-bit ptr
  ldr w20, [x20] // 32-bit value

  // if/else if/else
  cmp w20, w19
  bge elseif

  // print too low
  ldr x0, =toolow
  bl printf
  b.al endif
elseif:
  cmp w20, w19 
  ble else 

  // print too high
  ldr x0, =toohigh
  bl printf
  b.al endif
else:
  // print you got it
  ldr x0, =yougotit
  bl printf
endif: // the end of the if/else if/else

  b.al loop

done:
  ldr lr, [sp]
  ldr x19, [sp, #8]
  ldr x20, [sp, #16]
  add sp, sp, #32
  ret

.data
enterguess: .asciz "Enter your guess: "
scanffmt: .asciz "%d"
toolow: .asciz "Too low\n"
toohigh: .asciz "Too high\n"
yougotit: .asciz "You got it!\n"
theguess: .word 0 // space for scanf to set
