#include <iostream>
#include <string>
using namespace std;

int main() {
  string s = "hello"; 
  cout << s.size() << endl;

  string s2 = ", world!";
  string combo = s + s2;
  cout << combo << endl;

  int indexOfH = s.find('h');
  int indexOfL = s.find('l');
  int indexOfZ = s.find('z');
  cout << indexOfH << " " << indexOfL << " " << indexOfZ << endl;

  // let's convert "hello" to "hola"
  s.replace(1, 4, "ola");
  cout << s << endl;

  // let's extract "la" from "hola"
  string la = s.substr(2, 2);
  cout << la << endl;

  return 0;
}
