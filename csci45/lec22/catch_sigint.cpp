#include <iostream>
#include <signal.h>
#include <thread>
#include <chrono>
using namespace std;

void sigint_handler(int sid) {
  cout << "\nHaha, I'm not going to let you end me!\n";
  cout << "signal id: " << sid << endl;
}

int main() {
  // let's handle SIGINT (Ctrl-C) 
  signal(SIGINT, sigint_handler);
  signal(SIGQUIT, sigint_handler);

  int i = 0;
  while (true) {
    cout << i << endl;
    i++;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  return 0;
}
