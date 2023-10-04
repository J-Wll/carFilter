#include <iostream>
#include <limits>
#include <string>
#include <cctype>

using namespace std;

// Conditions for input validation
bool makeValidate(int inp){return inp >= 1 && inp <= 4 ? true : false;}
bool yearValidate(int inp){return inp >= 1995 && inp <= 2015 ? true : false;}
bool cylValidate(int inp){return inp == 1 || inp == 2 ? true : false;}

// Matches car names to number input
string getMake(int inp){
  switch(inp){
    case 1: return "Ford";
    case 2: return "Nisan";
    case 3: return "Volvo";
    case 4: return "Jaguar";
  }
}

// Takes and validates numeric input based on function condition
int getInp(string question, bool (*func)(int)) {
  int inp;
  bool fail = false;

  do {
    cout << "\n" << question << "\n" << "Or enter -1 to QUIT" << "\n";
    cin >> inp;
    if (inp == -1){
      cout << "QUITTING\n\nGoodbye";
      exit(0);
    }
    fail = cin.fail();

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

// Switch statement for cylinder input, calling getInp with the right question and returning the correct cylinder amount for each input
string getCyl(int makeNum){
  int cyl;
  switch(makeNum){
    case 1:{
      int cyl = getInp("How many cylinders does your Ford have? Please enter 1 or 2\n1) 6\n2) 8", cylValidate);
      return cyl == 1 ? "06" : "08";}
    case 2:{
      int cyl = getInp("How many cylinders does your Nisan have? Please enter 1 or 2\n1) 4\n2) 6", cylValidate);
      return cyl == 1 ? "04" : "06";}
    case 3:{
      int cyl = getInp("How many cylinders does your Volvo have? Please enter 1 or 2\n1) 15\n2) 20", cylValidate);
      return cyl == 1 ? "15" : "20";}
    case 4:{
      int cyl = getInp("How many cylinders does your Jaguar have? Please enter 1 or 2\n1) 6\n2) 12", cylValidate);
      return cyl == 1 ? "06" : "12";}
    }
  }



int main() {

  const int makeNum = getInp("What is the make of the car? Please enter 1, 2, 3 or 4 for \n\n1) Ford\n2) Nisan\n3) Volvo\n4) Jaguar", makeValidate);
  const string carMake = getMake(makeNum);
  const char carChar = carMake[0];

  const string carCyl = getCyl(makeNum);
  
  const int yearMade = getInp("What was the year of manufacture? Note that only models made between 1995 and 2015 are supported by this service\n\nPlease enter an integer between 1995 and 2015", yearValidate);
  const string strYear = to_string(yearMade).substr(2,3);

  const string modelNum = carChar + strYear +carCyl;
  cout << "\n\nYour car filter model number is: "<<modelNum;
  cout << "\nThank you for using our service\n\nGoodbye";
}