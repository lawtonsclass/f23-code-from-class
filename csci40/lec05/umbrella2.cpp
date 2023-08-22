#include <iostream>
#include <string>
using namespace std;

int main() {
  string chanceOfRain, currentlyRaining;
  cout << "Is there a chance of rain? ";
  cin >> chanceOfRain;
  cout << "Is it currently raining? ";
  cin >> currentlyRaining;

  if (chanceOfRain == "yes" || currentlyRaining == "yes") {
    cout << "Bring an umbrella!\n";
  } else {
    cout << "Don't bring an umbrella!\n";
  }

  return 0;
}
