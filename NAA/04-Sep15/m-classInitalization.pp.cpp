// class_init.cpp
#include <iostream>
#include <string>
using namespace std;

class Item {
   int id = 0;               // default initializer
   string name{ "empty" };    // default initializer
   double volume;
public:
   Item() {}                               // uses defaults
   Item(const string& n) : name{ n } {}      // member list
   Item(const string& n, int i) : name{ n }, id{ i } {
      // volume is already created with garbage in it
      // you can not initialize any member here, 
      // it is too late and they are already created
   }
   void display() const { cout << name << " " << id << endl; }
};

int main() {
   Item a, b("apple"), c("grape", 6);
   a.display();
   b.display();
   c.display();
   return 0;
}