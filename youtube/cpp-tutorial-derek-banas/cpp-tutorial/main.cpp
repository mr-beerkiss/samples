#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

const auto KM_IN_MILE = 1.60934;

int main() {

  std::string sMiles;

  std::cout << "Enter Miles: ";
  getline(std::cin, sMiles);

  auto dbMiles = std::stod(sMiles);

  printf("%.1f miles equals %.4f kilometeres\n.", dbMiles, (dbMiles * KM_IN_MILE));

  return 0;
}
