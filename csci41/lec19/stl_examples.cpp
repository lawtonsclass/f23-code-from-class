#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

struct Pokemon {
  int number;
  std::string name;
  std::string type;
};

// we need a way to order pokemon
bool operator<(const Pokemon& a, const Pokemon& b) {
  return a.number < b.number;
}

int main() {
  // set is a BST, so it needs to know how to order our stuff
  set<Pokemon> ourPokemonCards;  // start out empty
  ourPokemonCards.insert({4, "Charmander", "Fire"});
  ourPokemonCards.insert({1, "Bulbasaur", "Grass/Poison"});
  ourPokemonCards.insert({7, "Squirtle", "Water"});

  cout << ourPokemonCards.count({7, "Squirtle", "Water"}) << endl;
  cout << ourPokemonCards.count({25, "Pikachu", "Electric"}) << endl;

  for (set<Pokemon>::iterator it = ourPokemonCards.begin();
       it != ourPokemonCards.end(); it++) {
    cout << it->number << " " << it->name << " " << it->type << endl;
  }

  for (const Pokemon& p : ourPokemonCards) {
    cout << p.number << " " << p.name << " " << p.type << endl;
  }


  cout << "\n\n---\n\n";

  // map is a BST with separate keys and values
  map<int, Pokemon> numberToPokemon;  // start out empty
  numberToPokemon.insert(std::pair<int, Pokemon>(4, {4, "Charmander", "Fire"}));
  // or, equivalently: numberToPokemon.emplace(4, {4, "Charmander", "Fire"});
  numberToPokemon.insert(std::pair<int, Pokemon>(1, {1, "Bulbasaur", "Grass/Poison"}));
  numberToPokemon.insert(std::pair<int, Pokemon>(7, {7, "Squirtle", "Water"}));

  cout << numberToPokemon.at(4).name << endl;

  for (const auto& p : numberToPokemon) {
    // p is a std::pair
    // it has a p.first and a p.second (key is first, value is second)
    cout << p.first << ": ";
    cout << p.second.number << " " << p.second.name << " " << p.second.type
         << endl;
  }

  return 0;
}
