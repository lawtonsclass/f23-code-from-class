#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
  struct sysinfo test;
  printf("%ld\n", sizeof(test));
  printf("%ld\n", sizeof(test.uptime));

  unsigned int totalram_addr = &test.totalram;
  unsigned int starting_addr = &test;
  printf("%d\n", totalram_addr - starting_addr);
  
  return 0;
}
