#include <iostream>
#include <string>
#include <vector>

int main() {
  char cString[] ={ 'A', ' ', 'S', 't', 'r', 'i', 'n', 'g', '\0'};

  std::cout << cString << "\nArray size: " << sizeof(cString) << "\n";

  std::vector<std::string> strVec(10);

  std::string str("I'm a string");

  return 0;
}