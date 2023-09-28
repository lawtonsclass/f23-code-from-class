#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// the keys of the hash table
struct WordPair {
  string lastLastWord;
  string lastWord;
};

// unordered_map requires a way to hash WordPairs
class WordPairHash {
 public:
  size_t operator()(const WordPair& wp) const {
    hash<string> string_hash;
    return string_hash(wp.lastLastWord) + string_hash(wp.lastWord);
  }
};

// unordered_map also needs a way to check WordPairs for equality
bool operator==(const WordPair& wp1, const WordPair& wp2) {
  return wp1.lastLastWord == wp2.lastLastWord && wp1.lastWord == wp2.lastWord;
}

void convertToLowerCase(string& s) {
  for (char& c : s) c = tolower(c);
}

int main(int argc, char* argv[]) {
  srand(time(0));

  unordered_map<WordPair, vector<string>, WordPairHash> completionMap;

  ifstream ifs(argv[1]);  // open file

  string lastLastWord, lastWord, nextWord;

  ifs >> lastLastWord >> lastWord;  // read first two words
  convertToLowerCase(lastLastWord);
  convertToLowerCase(lastWord);

  while (ifs >> nextWord) {
    convertToLowerCase(nextWord);
    // add prediction to the hash table
    WordPair key = {lastLastWord, lastWord};
    if (completionMap.count(key) == 0)
      completionMap.emplace(key, vector<string>({nextWord}));
    else
      completionMap.at(key).push_back(nextWord);
    // advance lastLastWord and lastWord
    lastLastWord = lastWord;
    lastWord = nextWord;
  }

  ifs.close();

  // randomly pick a starting word pair
  auto it = completionMap.begin();
  for (int i = 0; i < (rand() % completionMap.size()); i++) it++;
  WordPair currentPair = it->first;

  // calculate a length 100 sentence
  vector<string> sentence = {currentPair.lastLastWord, currentPair.lastWord};
  for (int i = 0; i < 98; i++) {
    // we might need to stop early
    if (completionMap.count(currentPair) == 0) break;
    // predict the net word using the completionMap
    vector<string>& possibilities = completionMap.at(currentPair);
    // pick a random next word
    string nextWord = possibilities.at(rand() % possibilities.size());
    // add the next word
    sentence.push_back(nextWord);
    // update currentPair
    currentPair.lastLastWord = currentPair.lastWord;
    currentPair.lastWord = nextWord;
  }

  // output the built-up sentence
  for (string word : sentence) cout << word << ' ';
  cout << endl;

  return 0;
}
