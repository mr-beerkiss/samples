#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

int main() {
  // 1 - 18, 21, 50 > 65
  std::string sAge;
  
  std::cout << "Enter your age: ";

  getline(std::cin, sAge);

  int nAge = std::stoi(sAge);

  if ((nAge >= 1 && nAge <= 18) || nAge == 21 || nAge == 50 || nAge >= 65) {
    std::cout  << nAge << " is an important age!" << std::endl;
  } else {
    std::cout << nAge << " is not a very important age." << std::endl;
  }
}