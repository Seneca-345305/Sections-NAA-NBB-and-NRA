#include <iostream>
using namespace std;


int getInt(bool (*isValid)(int));
int main() {
   cout << "07-Sep29 OOP345 NBB" << endl;
   cout << "Enter your age: ";
   int age = getInt([](int num) {return num >= 18 && num <= 65; });
   cout << "age: " << age << endl;
   cout << "Enter the number of students: ";
   int nos = getInt([](int num) {
      return num >= 10 && num <= 35;
   });
   cout << "No of students in class: " << nos << endl;
   return 0;
}
int getInt(bool (*isValid)(int)) {
   int num{};
   bool done = false;
   do {
      cin >> num;
      if (cin.fail()) {
         cin.clear();
         cout << "Invalid Integer, please try again\n> ";
      }
      else {
         if (cin.peek() != '\n') {
            cout << "Only an Integer, Please try again\n> ";
         }
         else if (isValid(num)) {
            done = true;
         }
         else {
            cout << "Invaid value...\n> ";
         }
      }
      cin.ignore(10000, '\n');
   } while (!done);
   return num;
}