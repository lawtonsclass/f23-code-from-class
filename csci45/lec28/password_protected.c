#include <stdio.h>
#include <string.h>

int main() {
  // ask for a password
  printf("Enter the password: ");

  // string to fill in with the user's password
  char user_input[100];

  scanf("%s", user_input);

  // compare it with the real password
  if (strcmp(user_input, "I<3CSCI45") == 0) {
    printf("Password correct!\n");
  } else {
    printf("ACCESS DENIED!!!\n");
  }

  return 0;
}
