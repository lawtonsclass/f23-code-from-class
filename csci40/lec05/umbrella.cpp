#include <iostream>
#include <string>
using namespace std;

int main() {
  string cloudy, chanceOfRain;
  cout << "Is it cloudy today? ";
  cin >> cloudy;
  cout << "Is there a chance of rain? ";
  cin >> chanceOfRain;

  if (cloudy == "yes" && chanceOfRain == "yes") {
    cout << "Bring an umbrella!\n";
  } else {
    cout << "Don't bring an umbrella!\n";
  }

  return 0;
}
