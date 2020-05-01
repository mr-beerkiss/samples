#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>


int main() {

  std::string sQuestion ("Enter number 1: ");
  std::string sNum1, sNum2;

  std::cout << sQuestion;
  getline(std::cin, sNum1);
  std::cout << "Enter number 2: ";
  getline(std::cin, sNum2);

  auto nNum1 = std::stoi(sNum1);
  auto nNum2 = std::stoi(sNum2);

  printf("%d + %d = %d\n", nNum1, nNum2, (nNum1 + nNum2));

  printf("%d - %d = %d\n", nNum1, nNum2, (nNum1 - nNum2));

  printf("%d * %d = %d\n", nNum1, nNum2, (nNum1 * nNum2));

  printf("%d / %d = %d\n", nNum1, nNum2, (nNum1 / nNum2));

  printf("%d %% %d = %d\n", nNum1, nNum2, (nNum1 % nNum2));

  return 0;
}
