#include <iostream>
#include <limits>
#include <string>
#include <cctype>

using namespace std;

// Asks for, gets and validates numeric input+
// Condition input
// https://stackoverflow.com/questions/59656675/how-can-i-pass-a-condition-to-a-function-in-c

bool makeValidate(int inp){return inp >= 1 && inp <= 4 ? true : false;}
bool yearValidate(int inp){return inp >= 1995 && inp <= 2015 ? true : false;}
// bool makeValidate(int inp){return inp >= 1 && inp <= 4 ? true : false;}

string getMake(int inp){
  switch(inp){
    case 1: return "Ford";
    case 2: return "Nisan";
    case 3: return "Volvo";
    case 4: return "Jaguar";
  }
}

int getInp(string question, bool (*func)(int)) {
  int inp;
  bool fail = false;

  do {
    cout << "\n" << question << "\n" << "Enter 0 to QUIT" << "\n";
    cin >> inp;
    if (inp == 0){
      cout << "QUITTING\n\nGoodbye";
      exit(0);
    }
    fail = cin.fail();
    // cout << "\n" << inp << "\n" << inp % 100 << "\n";
    if (typeid(inp) == typeid(int) && !func(inp)) {
      fail = true;
    }
    if (fail) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "\n\033[1;31mInvalid input, please follow input requirements\033[0m\n";
    }
  } while (fail);

  return inp;
}

int main() {
  // Map for associating input with correct make and further details, ie jag can
  // only have 6 cylinders
  // https://stackoverflow.com/questions/64681330/how-to-map-multiple-values-in-c
  
  const int makeNum = getInp("What is the make of the car? Please enter 1, 2, 3 or 4 for \n\n1) Ford\n2) Nisan\n3) Volvo\n4) Jaguar", makeValidate);
  const string carMake = getMake(makeNum);
  const char carChar = carMake[0];
  const int yearMade = getInp("What was the year of manufacture? Note that only models made between 1995 and 2015 are supported by this service\n\nPlease enter an integer between 1995 and 2015", yearValidate);
  const string strYear = to_string(yearMade).substr(2,3);

  const string modelNum = carChar + strYear;
  cout << "Your car filter model number is: "<<modelNum;
  cout << "\nThank you for using our service\n\nGoodbye";
}