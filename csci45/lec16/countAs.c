#include <stdio.h>

int main() {
  FILE* fp = fopen("file.txt", "r");

  int aCount = 0;

  printf("EOF on this machine is: %d\n", EOF); 

  while (1) {
    int c = fgetc(fp);
    if (c == EOF) {
      break;
    } else if (c == 'a') {
      aCount++;
    }
  }

  fclose(fp);

  printf("# of 'a's: %d\n", aCount);

  return 0;
}
