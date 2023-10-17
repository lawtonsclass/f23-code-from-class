#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  srand(time(0));

  ifstream ifs("SwedishWords.txt");

  vector<string> words;
  // read every word in the file into words
  string word;
  while (ifs >> word) {
    words.push_back(word);
  }

  ifs.close();

  // get two random words out of the vector
  string word1 = words.at(rand() % words.size());
  string word2 = words.at(rand() % words.size());
  cout << word1 << word2 << endl;

  return 0;
}
