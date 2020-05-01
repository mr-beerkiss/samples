
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

std::vector<int> Range(int start, int end, int step);

int main() {

  printf("\nvec 1 = ");

  auto vec1 = Range(0, 5, 1);

  for (auto num: vec1 ) std::cout << num << " ";

  printf("\nvec 2 = ");

  auto vec2 = Range(1, 10, 3);

  for (auto num: vec2 ) std::cout << num << " ";

  printf("\nvec 3 = ");

  auto vec3 = Range(0, 50, 5);

  for (auto num: vec3 ) std::cout << num << " ";

  return 0;
}

std::vector<int> Range(int start, int end, int step) {
  std::vector<int> retVal;

  for (int i=start; i < end; i += step) {
    retVal.push_back(i);
  }

  return retVal;
} 