#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
// Needed for std::iota
#include <numeric>

int main() {

  std::vector<int> vecnNums(10);

  std:iota(std::begin(vecnNums), std::end(vecnNums), 1);

  for (auto num: vecnNums) {
    if (num % 2 == 0 ) {
      std::cout << num << std::endl;
    }
  }

  return 0;
}