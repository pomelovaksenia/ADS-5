// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>

template <typename T, int size>
class TStack {
 private:
  T mass[size] = {0};
  int a;

 public:
  TStack() { a = -1; }
  void push(const T& value) {
    if (full()) {
      throw std::string("  empty!");
    } else {
      mass[++a] = value;
    }
  }
  T pol() const { return mass[a]; }
  T pop() { return mass[a--]; }
  int pri() const { return a; }
  bool empty() const { return a == -1; }
  bool full() const { return a == size; }
};

#endif  // INCLUDE_TSTACK_H_
