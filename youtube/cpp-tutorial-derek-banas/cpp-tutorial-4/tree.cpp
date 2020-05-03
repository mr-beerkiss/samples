#include <iostream>
#include <string>
#include <vector>
#include <numeric>

std::vector<int> Range(int start, int end, int step);

int main() {

  int treeHeight = 0;
  std::cout << "How tall is the tree: ";
  std::cin >> treeHeight;

  std::vector<char> leaves(treeHeight*2, ' ');
  int midPoint = leaves.size() / 2;
  leaves[midPoint] = '#';

  int row = 0;
  int l = midPoint - 1, r = midPoint + 1;

  while (row < treeHeight) {
    for (char c: leaves) std::cout << c;
    std::cout << std::endl;
    leaves[l--] = '#';
    leaves[r++] = '#';
    row++;
  }

  for (auto i: Range(0, midPoint+1, 1)) {
    if (i == midPoint) {
      std::cout << '#' << std::endl;
    } else {
      std :: cout << ' ';
    }
  }

  return 0;
}

std::vector<int> Range(int start, int end, int step) {
  std::vector<int> vec;
  for (auto i=start; i < end; i++) {
    vec.push_back(i);
  }
  return vec;
}