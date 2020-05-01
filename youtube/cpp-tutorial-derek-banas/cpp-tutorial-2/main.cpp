#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

int main() {
  // Age 5 "Go to Kindergarten"

  // Age 6 through 17 -> 1 through 12

  // Age 17 > Go to college

  // age < 5 "TOo you for schoo"

  // age = 8 Go to Grade 3

  std::string sAge = "0";

  std::cout << "Enter age: ";
  getline(std::cin, sAge);

  int nAge = std::stoi(sAge);

  if (nAge < 5) {
    std::cout << "Too young for school" << std::endl;
  } else if (nAge == 5) {
    std::cout << "Go to Kindergarten" << std::endl;
  } else if (nAge >= 6 && nAge <= 17) {
    std::cout << "Go to Grade " << nAge - 5 << std::endl;
  } else {
    std::cout << "Go to college" << std::endl;
  }

  return 0;
}