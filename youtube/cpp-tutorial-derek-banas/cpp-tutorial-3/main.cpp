#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
// Needed for std::iota
#include <numeric>
int main() {
  std::vector<int> myVec(10);

  std::iota(std::begin(myVec), std::end(myVec), 0);

  for (int i=0; i < myVec.size(); ++i) {
    std::cout << myVec[i] << std::endl;
  }

  for (auto y: myVec) std::cout << y << std::endl;

  return 0;
}