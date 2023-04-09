// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int Prior(char c) {
  switch (c) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '-':
      return 2;
    case '+':
      return 2;
    case '/':
      return 3;
    case '*':
      return 3;
  }
  return -1;
}


std::string infx2pstfx(std::string inf) {
  TStack<char, 100> stck1;
  std::string itog;
  int res = 0;
  for (char a : inf) {
    bool iter = true;
    if (Prior(a) == -1) {
      itogo += a;
      itogo += ' ';
      iter = false;
    }
    if (Prior(a) == 0) {
      stck1.push(a);
      iter = false;
    }
    if (Prior(a) > Prior(stck1.pol())) {
      stck1.push(a);
      iter = false;
    }
    if (stck1.empty() && Prior(a) != -1) {
      stck1.push(a);
      iter = false;
    }
    if (iter && a != ')') {
      while (Prior(stck1.pol()) >= Prior(a)) {
        itogo += stck1.pop();
        itogo += ' ';
      }
      stck1.push(a);
    }
    if (a == ')') {
      while (stck1.pol() != '(') {
        itogo += stck1.pop();
        itogo += ' ';
      }
      stck1.pop();
    }
    if (res == inf.size() - 1) {
      while (!stck1.empty()) {
        itog += stck1.pop();
        if (stck1.pri() != -1) itogo += ' ';
      }
    }
    ++res;
  }
  return itogo;
}

int eval(std::string pref) {
  TStack<int, 100> stck2;
  for (char z : pref) {
    if (z == '+') {
      int i = stck2.pop();
      i = i + stck2.pop();
      stck2.push(i);
    }
    if (z == '-') {
      int i = stck2.pop();
      i = stck2.pop() - i;
      stck2.push(i);
    }
    if (z == '/') {
      int i = stck2.pop();
      i = stck2.pop() / i;
      stck2.push(i);
    }
    if (z == '*') {
      int i = stck2.pop();
      i = i * stck2.pop();
      stck2.push(i);
    }
    if (z == ' ') {
      continue;
    }
    if ((z - '0') > 0) {
      int i = z - '0';
      stck2.push(i);
    }
  }
  return stck2.pol();
}
