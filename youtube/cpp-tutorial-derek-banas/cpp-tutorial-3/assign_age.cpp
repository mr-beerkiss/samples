#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
// Needed for std::iota
#include <numeric>

void AssignAge(int age);
int AssignAge2(int age);
void AssignAge3(int* age);


int main() {
  int age = 43;

  AssignAge(age);

  std::cout << "New age: " << age << std::endl;

  std::cout << "New age: " << AssignAge2(age) << std::endl;

  int *pAge = NULL;

  pAge = &age;

  std::cout << "Address: " << pAge << std::endl;

  std::cout << "Value at address: " << *pAge << std::endl;

  int intArray[] = {1, 2, 3, 4};
  int* pIntArray = intArray;

  std:: cout << "1st " << *pIntArray << " Address " << pIntArray << std::endl;

  pIntArray++;

  std:: cout << "2nd " << *pIntArray << " Address " << pIntArray << std::endl;

  pIntArray--;

  std:: cout << "1st " << *pIntArray << " Address " << pIntArray << std::endl;

  AssignAge3(&age);
  std::cout << "Age: " << age  << std::endl;

  return 0;
  
}

// FUNCTIONS

void AssignAge(int age) {
  age = 24;
}

int AssignAge2(int age) {
  age = 24;
  return age;
}

void AssignAge3(int* age) {
  *age = 24;
}