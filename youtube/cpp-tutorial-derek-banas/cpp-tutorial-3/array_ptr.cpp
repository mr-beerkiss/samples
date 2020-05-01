#include <iostream>
#include <vector>
#include <string>
#include <numeric>

void DoubleArray(int* arr, int size);

int main() {
  int nArr[] = {1, 2, 3, 5, 8, 13, 21};
   
  DoubleArray(nArr, sizeof(nArr) / sizeof(*nArr));

  for (auto num: nArr) std::cout << num << std::endl;

  return 0;
}

void DoubleArray(int* arr, int size) {
  for (int i=0; i < size; i++, arr++ ) {
    *arr = *arr * 2;
  }
}