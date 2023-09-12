#ifndef ADDER_H
#define ADDER_H

template <class T>
class Adder {
  public:
    T add() const;

    T x;
    T y;
};

// The implementation of a templated class cannot be compiled
// separately (-c). The reason why is because templated
// methods/functions ***aren't actual code***.
template <class T>
T Adder<T>::add() const {
  return x + y;
}


#endif /* end of include guard: ADDER_H */
