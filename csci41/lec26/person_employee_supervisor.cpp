#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
  public:
    Person(string name, int age) : name(name), age(age) {}
    virtual string to_string() const { return name + " " + std::to_string(age); }

  protected:
    string name;
    int age;
};

class Employee : public Person {
  public:
    Employee(string name, int age, double salary, int employeeID)
      : Person(name, age), salary(salary), employeeID(employeeID) {}

    string to_string() const override {
      // attach salary & employeeID to the to_string result for Person
      return Person::to_string() + " " + std::to_string(salary) + " " + std::to_string(employeeID);
    }

  protected:
    double salary;
    int employeeID;
};

class Supervisor : public Employee {
  public:
    Supervisor(string name, int age, double salary, int employeeID, const vector<Employee*>& supervising)
      : Employee(name, age, salary, employeeID), supervising(supervising) {}

    string to_string() const override {
      string res = Employee::to_string();

      // add each employee that the supervisor is supervising
      for (Employee* e : supervising) {
        res += "\n\t" + e->to_string();
      }

      return res;
    }

  protected:
    vector<Employee*> supervising;
};

int main() {
  Employee lawton("Lawton", 31, 3.14, 8675309);
  Employee lonzo("Lonzo", 3, 1000000, 8675310);
  Supervisor bill("Bill", 32, 100000000, 8675308, {&lawton, &lonzo});

  cout << lawton.to_string() << endl;
  cout << lonzo.to_string() << endl;
  cout << bill.to_string() << endl;

  return 0;
}
