#include <iostream>
#include <unistd.h> // for fork
#include <sys/wait.h> // for wait
using namespace std;

int main() {
  const int size = 10'000'000;
  int* arr = new int[size];
  int sum = 0;

  if (fork() == 0) {
    // I'm the child!
    cout << "Hello from the child!" << endl;

    for (int i = 0; i < size/2; i++) {
      sum += arr[i];
    }
  } else {
    // I'm the parent!
    // sleep(1);
    cout << "Hello from the parent!" << endl;

    for (int i = size/2; i < size; i++) {
      sum += arr[i];
    }

    // the parent should wait for the child to exit
    wait(nullptr);
  }


  return 0;
}
