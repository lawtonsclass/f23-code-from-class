#include <stdio.h>

// this variable is a hack--we're using it to reference the fictional
// LED that we're pretending exists at the physical addr. 0x86753090
int led_mem __attribute__((section(".mySection")));

void look_at_led() {
  int* led = (int*)0x86753090;

  if (*led > 0) printf("🔴\n");
  else printf("⚪\n");
}

int main() {
  int* led = (int*)0x86753090; // this is the address of the led!
                               // this line creates a pointer to the
                               // address 0x86753090--we're pretending
                               // that there's an int there
  
  *led = 0; // turn it off
  look_at_led();
  *led = 255; // turn it on
  look_at_led();


  return 0;
}
