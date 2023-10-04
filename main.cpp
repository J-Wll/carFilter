#include <iostream>
#include <limits>

using namespace std;

// Asks for, gets and validates numeric input+
// Condition input
// https://stackoverflow.com/questions/59656675/how-can-i-pass-a-condition-to-a-function-in-c

bool makeValidate(int inp){return inp >= 1 && inp <= 4 ? true : false;}

int getInp(string question, bool (*func)(int)) {
  int inp;
  bool fail = false;

  do {
    cout << "\n" << question << "\n";
    cin >> inp;
    fail = cin.fail();
    // define variable condition based on argument to function, checked below,
    // ie: replacing 0 with in 1,2,3,4 or between 85-95
    if (typeid(inp) == typeid(int) && !func(inp)) {
      fail = true;
    }
    if (fail) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "\n\033[1;31mInvalid input, enter a positive number\033[0m\n";
    }
  } while (fail);

  return inp;
}

int main() {
  std::cout << "Hello World!\n";
  // Map for associating input with correct make and further details, ie jag can
  // only have 6 cylinders
  // https://stackoverflow.com/questions/64681330/how-to-map-multiple-values-in-c
  int makeNum = getInp("What is the make of the car? Please enter 1, 2, 3 or 4 for \n\n1)Ford\n2)Nisan\n3)Volvo\n4)Jaguar", makeValidate);
  string carMake = "f";
  // int yearMade = getInp("What was the year of manufacture? Note that only models made between 1995 and 2015 are supported by this service");
}