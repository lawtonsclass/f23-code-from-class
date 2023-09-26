#include <iostream>
using namespace std;

class Point {
  public:
    double x;
    double y;

    void negate() {
      // in here, I can talk about x & y and they are the x & y that
      // belong to the current object that negate has been called on
      x = -x;
      y = -y;
    }

    Point add(const Point& o) {
      Point result;
      result.x = x + o.x;
      result.y = y + o.y;
      return result;
    }

    void scale(double c) {
      x = x * c;
      y = y * c;
    }
};

int main() {
  Point p = {2, 3}; // (2, 3)
  Point p2 = {2.5, 3.5};
  Point q; // (?, ?)
  q.x = 4.5;
  q.y = 7.89;

  cout << "(" << p.x << ", " << p.y << ")" << endl;
  cout << "(" << q.x << ", " << q.y << ")" << endl;

  Point p_plus_q = p.add(q);
  cout << "(" << p_plus_q.x << ", " << p_plus_q.y << ")" << endl;
  
  p.negate();
  cout << "(" << p.x << ", " << p.y << ")" << endl;

  q.scale(2);
  cout << "(" << q.x << ", " << q.y << ")" << endl;

  return 0;
}
