#include <iostream>
using namespace std;

struct Point {
  // every Point has an x and y coordinate
  double x;
  double y;
};

Point add(Point a, Point b) {
  Point result;

  result.x = a.x + b.x;
  result.y = a.y + b.y;

  return result;
}

void negatePoint(Point& a) {
  a.x = -a.x;
  a.y = -a.y;
}

int main() {
  Point p = {2, 3}; // (2, 3)
  Point p2 = {2.5, 3.5};
  Point q; // (?, ?)
  q.x = 4.5;
  q.y = 7.89;

  cout << "(" << p.x << ", " << p.y << ")" << endl;
  cout << "(" << q.x << ", " << q.y << ")" << endl;

  Point p_plus_q = add(p, q);
  cout << "(" << p_plus_q.x << ", " << p_plus_q.y << ")" << endl;
  
  negatePoint(p);
  cout << "(" << p.x << ", " << p.y << ")" << endl;

  return 0;
}
