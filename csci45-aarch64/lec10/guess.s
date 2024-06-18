.global guessTheNumberGame
.type guessTheNumberGame, %function
.func guessTheNumberGame
guessTheNumberGame:
  // void guessTheNumberGame(int up_to);
  // up_to is in r0

  push {r4-r11, lr}

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

  // up_to is already in r0
  bl getRandomNumberFrom1To
  mov r4, r0 // save n in a saved register

  mov r5, #-1
loop:
  cmp r5, r4
  beq done
  
  // loop body
  ldr r0, =enterguess
  bl printf

  ldr r0, =scanffmt
  ldr r1, =theguess
  bl scanf
  // mov theguess into r5
  ldr r5, =theguess
  ldr r5, [r5]

  // if/else if/else
  cmp r5, r4
  bge elseif

  // print too low
  ldr r0, =toolow
  bl printf
  bal endif
elseif:
  cmp r5, r4 
  ble else 

  // print too high
  ldr r0, =toohigh
  bl printf
  bal endif
else:
  // print you got it
  ldr r0, =yougotit
  bl printf
endif: // the end of the if/else if/else

  bal loop

done:
  pop {r4-r11, pc}

.data
enterguess: .asciz "Enter your guess: "
scanffmt: .asciz "%d"
toolow: .asciz "Too low\n"
toohigh: .asciz "Too high\n"
yougotit: .asciz "You got it!\n"
theguess: .word 0 // space for scanf to set
