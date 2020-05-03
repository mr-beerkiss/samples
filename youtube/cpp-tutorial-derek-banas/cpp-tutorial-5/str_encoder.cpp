#include <iostream>
#include <string>
#include <vector>

void myVersion(std::string input);
void dereksVersion(std::string input);

// by substracting 23 from any character code we're guaranteed to get back a two digit number 
// for any character in the range A-z
const int ASCII_DOUBLE_DIGIT_GUARANTEE = 23;

int main() {

  std::string inputStr;

  std::cout << "Enter a string to encode: ";
  std::cin >> inputStr;
  // transform(inputStr.begin(), inputStr.end(), inputStr.begin(), ::toupper);

  dereksVersion(inputStr);
  myVersion(inputStr);
  

  return 0;
}


void dereksVersion(std::string input) {
  std::string secretString = "";

  for (auto c: input) secretString += std::to_string((int)c - ASCII_DOUBLE_DIGIT_GUARANTEE);

  std::cout << "Secret String = " << secretString << "\n";

  input = "";

  // Decode secret string
  for (auto i=0; i < secretString.length(); i += 2) {
    int code = std::stoi(secretString.substr(i, 2));
    code += ASCII_DOUBLE_DIGIT_GUARANTEE;
    input += (char)code;
  }

  std::cout << "Decoded String = " << input << "\n";
}

void myVersion(std::string input) {
  std::vector<int> asciiCodes;

  for (auto c: input) asciiCodes.push_back((int)c - ASCII_DOUBLE_DIGIT_GUARANTEE);

  std::cout << "Encoded String = ";
  for (auto i=0; i < asciiCodes.size(); ++i) {
    if (i < asciiCodes.size() - 1)
      std::cout << asciiCodes[i] << ", ";
    else 
      std::cout << asciiCodes[i] << "\n";
  }

  std::cout << "Decoded String = ";
  for (auto i=0; i < asciiCodes.size(); ++i) {
    if (i < asciiCodes.size() - 1)
      std::cout << (char)(asciiCodes[i] + ASCII_DOUBLE_DIGIT_GUARANTEE);
    else 
      std::cout << (char)(asciiCodes[i] + ASCII_DOUBLE_DIGIT_GUARANTEE) << "\n";
  }
}