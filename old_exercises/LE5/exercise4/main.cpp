#include <iostream>
using namespace std;

class base {
protected:
  int c1;

public:
  base(int c) {
    c1 = c;
    cout << "constructor of base called" << endl;
  }
  ~base() { cout << "destructor of base called" << endl; }
};

class base2 : public base {
public:
  base2(int c1) : base(c1) { cout << "constructor of base2 called" << endl;}
  ~base2() { cout << "destructor of base2 called" << endl; }
};

class child : public base2 {
public:
  child(int c1) : base2(c1) {
    cout << "constructor of child called" << endl;
  }
  ~child() { cout << "destructors  of child called" << endl; }
};

int main() {
  child c1(3);
  return 0;
}

/*
 Base class constructors are called first and the derived
  class constructors are called next in single inheritance.
Destructor is called in reverse sequence of constructor invocation i.e.
  The destructor of the derived class is called first and the destructor of the
base is called next.

when we create an object of derived class, all of the members of derived class must be initialized
 but the inherited members in derived class can only be initialized by the base class’s constructor as the definition of
 these members exists in base class only.
 This is why the constructor of base class is called first to initialize all the inherited members.
 */
