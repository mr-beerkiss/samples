
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

std::vector<int> Range(int start, int end, int step);

int main() {

  // How much to invest: 
  // Interest Rate: 
  // How many years:

  int  nYears;
  double dbPrincipal, dbInterestRate;

  std::cout << "How much to invest: ";
  std::cin >> dbPrincipal;
  std::cout << "\nInterest Rate: ";
  std::cin >> dbInterestRate;
  std::cout << "\nHow many years: ";
  std::cin >> nYears;

  for (auto _: Range(1, nYears, 1)) {
    dbPrincipal *= 1 + dbInterestRate * .01;
  }

  printf("\nCompounded interest is: %.2f\n", dbPrincipal);



  return 0;
}

std::vector<int> Range(int start, int max, int step) {
  std::vector<int> range;

  int i = start;

  while (i <= max) {
    range.push_back(i);
    i += step;
  }

  return range;
} 