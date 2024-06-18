#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guessTheNumberGame(int up_to);

int getRandomNumberFrom1To(int n) {
  return (rand() % n) + 1;
}

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

int main() {
  srand(time(0));

  int up_to;
  printf("Enter up_to: ");
  scanf("%d", &up_to);

  guessTheNumberGame(up_to);

  return 0;
}

