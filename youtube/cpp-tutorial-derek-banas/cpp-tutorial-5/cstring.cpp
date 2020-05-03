#include <iostream>
#include <string>
#include <vector>

int main() {
  char cString[] ={ 'A', ' ', 'S', 't', 'r', 'i', 'n', 'g', '\0'};

  std::cout << cString << "\nArray size: " << sizeof(cString) << "\n";

  std::vector<std::string> strVec(10);

  std::string str("I'm a string");
  strVec[0] = str;

  std::cout << strVec[0] << "\n";
  std::cout << "First char: " << str.front() << ", Last char: " << str.back()
    << "\nLength: " << str.length() << "\n";

  // copy a string
  std::string str2(str);
  strVec[1] = str2;

  // copy a string portion
  std::string str3(str, 4);
  strVec[2] = str3;

  // repeating characters
  std::string str4(12, '*');
  strVec[3] = str4;

  strVec[4] = str.append(" and you're not");

  // find substrings
  if (str.find("string") != std::string::npos)
    std::cout << "1st index " << str.find("string") << "\n";

  std::cout << "Substr " << str.substr(6, 6) << "\n";

  reverse(str.begin(), str.end());
  std::cout << "Reversed: " << str << "\n";

  // string transforms (toupper)
  transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
  std::cout << "Transformed toupper: " << str2 << "\n";

  transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
  std::cout << "Transformed tolower: " << str2 << "\n";

  // a -z 97 - 122
  // A - Z - 65 - 90
  char aChar = 'Z';
  int aInt = aChar;
  std::cout << "A code " << (int)'a' << "\n";

  std::string strNum = std::to_string(1+2);
  

  // for (auto s: strVec) std::cout << s << "\n";


  return 0;
}