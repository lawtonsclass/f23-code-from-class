#include "point.h"

// *implementation* of the Point class

void Point::negate() {
  // in here, I can talk about x & y and they are the x & y that
  // belong to the current object that negate has been called on
  x = -x;
  y = -y;
}

Point Point::add(const Point& o) const {
  Point result;
  result.x = x + o.x;
  result.y = y + o.y;
  return result;
}

void Point::scale(double c) {
  x = x * c;
  y = y * c;
}

// getters
double Point::getX() const {
  return x;
}

double Point::getY() const {
  // x = 42; // this should not be allowed!
  // y = 42;
  return y;
}

// setters
void Point::setX(double d) {
  x = d;
}

void Point::setY(double d) {
  y = d;
}

void Point::reset() {
  // the following code creates NEW local vars
  // called x & y -- they *shadow* the x & y member vars :(
  // double x = 0.0;
  // double y = 0.0;

  x = 0.0;
  y = 0.0;
}
