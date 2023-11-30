#include <iostream>
#include <string>
#include <vector>
using namespace std;

// this is an "abstract class"--it can't be instantiated
class MacLaptop {
 protected:  // protected lets us use these things in subclasses
  double price;
  int batteryLife;

 public:
  MacLaptop(double price, int batteryLife)
      : price(price), batteryLife(batteryLife) {}
  double getPrice() const { return price; }
  int getBatteryLife() const { return batteryLife; }

  virtual bool runsWindows() const = 0;  // pure virtual method
};

class MacBookAirIntel : public MacLaptop {
 protected:
  string processorModel;

 public:
  MacBookAirIntel(double price, int batteryLife, string processorModel)
      : MacLaptop(price, batteryLife), processorModel(processorModel) {}
  string getProcessorModel() const { return processorModel; }
  bool runsWindows() const override { return true; }
};

class MacBookProM1 : public MacLaptop {
 public:
  MacBookProM1(double price, int batteryLife) : MacLaptop(price, batteryLife) {}
  bool runsWindows() const override { return false; }
  bool isOwnedByAHipster() const { return true; }
};

int main() {
  /* MacLaptop ml(42, 42);  // can't do this */

  MacBookAirIntel mai(999, 8, "i5");
  MacBookProM1 mbpm1(9999, 42);

  cout << mai.getProcessorModel() << endl;
  cout << mai.getPrice() << endl;
  cout << mai.runsWindows() << endl;
  cout << mbpm1.getBatteryLife() << endl;
  cout << mbpm1.runsWindows() << endl;
  cout << mbpm1.isOwnedByAHipster() << endl;

  // we can treat subclasses like the base class!
  vector<MacLaptop*> v = {&mai, &mbpm1};
  cout << v.at(0)->runsWindows() << endl;

  return 0;
}
