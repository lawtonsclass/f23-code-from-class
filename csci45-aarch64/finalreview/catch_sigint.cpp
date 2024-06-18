#include <iostream>
#include <cstdlib>
#include <ctime>
#include <signal.h>
#include <unistd.h>
using namespace std;

void sigint_handler(int sid) {
  if (rand() % 10 == 0) {
    cout << "Okay, fine...\n";
    exit(0);
  }

  cout << "Haha, I'm not going to let you end me!\n";
}

int main() {
  srand(time(0));

  // let's handle SIGINT (Ctrl-C)
  signal(SIGINT, sigint_handler);

  while (true) {
    pause(); // waits for the next signal to occur
  }

  return 0;
}
