#include <iostream>
using namespace std;

int main() {
  for (int numHorses = 0; numHorses <= 100; numHorses++) {
    for (int numPigs = 0; numPigs <= 100; numPigs++) {
      for (int numRabbits = 0; numRabbits <= 100; numRabbits++) {
        // When I am here, I have chosen some amount of horses, pigs,
        // and rabbits. Every possibility will get a chance!
        
        int numAnimals = numHorses + numPigs + numRabbits;
        double price = numHorses*10 + numPigs*3 + numRabbits*0.50;

        if (numAnimals == 100 && price == 100.00) {
          // I found a solution!
          cout << numHorses << " horses, " << 
                  numPigs << " pigs, " << 
                  numRabbits << " rabbits\n";
        }
      }
    }
  }

  return 0;
}
