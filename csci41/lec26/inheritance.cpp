#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
public:
  Animal(string name, int age) : name(name), age(age) {}

  // generic talk method
  virtual void talk() const { 
    cout << "Animal noise\n"; 
  }

  // every subclass has access to these methods!
  // I don't have to rewrite them!
  string getName() const { return name; }
  void setName(const string& newName) { name = newName; }
  int getAge() const { return age; }
  void setAge(int newAge) { age = newAge; }

protected:
  // now these are visible to subclasses!
  string name;
  int age;
};

// If we do Dog : private Animal, all the inherited stuff from Animal
// that was public becomes private
class Dog : public Animal {
public:
  Dog(string name, int age, string college) 
    : Animal(name, age), college(college) { }

  // override the talk method!
  // C++ already knows this is virtual, and it is good practice to
  // include the override
  void talk() const override { 
    cout << "Go Dogs Go!\n"; 
  }

  void birthday() {
    age++;
  }

  // *new* getters and setters
  string getCollege() const { return college; }
  void setCollege(const string& newCollege) { college = newCollege; }

private:
  // *new* fields
  string college;
};

class Cat : public Animal {
public:
  Cat(string name, int age, string favoriteFood) 
    : Animal(name, age), favoriteFood(favoriteFood) { }

  // override the talk method!
  void talk() const override { 
    cout << "meow\n"; 
  }

  // *new* getters and setters
  string getFavoriteFood() const { return favoriteFood; }
  void setFavoriteFood(const string& newFavoriteFood) { favoriteFood = newFavoriteFood; }

private:
  // *new* fields
  string favoriteFood;
};

int main() {
  Dog victorE("Victor E.", 3, "Fresno State"); 

  // I can use Animal parts of victorE
  cout << victorE.getName() << endl;
  victorE.setName("Victor E. Bulldog");
  cout << victorE.getName() << endl;
  victorE.talk();
  victorE.birthday();
  cout << victorE.getAge() << endl;
  // victorE.age++; // still not allowed

  Cat lonzo("Alonzo", 3, "tuna");
  lonzo.talk();

  cout << endl;


  // I can make a vector of Animal pointers, and put pointers to derived classes inside!
  // This is because every Cat/Dog *is an* Animal!
  // I can treat a Cat/Dog like an Animal, and just call the Animal parts
  vector<Animal*> v = {&victorE, &lonzo};

  for (const Animal* a : v) {
    cout << a->getName() << ": ";
    a->talk();
  }

  return 0;
}
