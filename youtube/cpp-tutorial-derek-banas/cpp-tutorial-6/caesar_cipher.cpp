#include <iostream>
#include <string>

std::string CaesarCipher(std::string theString, int key, bool encrypt);
std::string CaesarCipher_2(std::string theString, int key, bool encrypt);

int main() {

  std::string theString = "Make me secret";
  std::string encryptedString = CaesarCipher(theString, 5, true);
  std::string decryptedString = CaesarCipher(encryptedString, 5, false);

  std::cout << "Input string: " << theString << "\n";
  std::cout << "Encrypted: " << encryptedString << "\n";
  std::cout << "Decrypted: " << decryptedString << "\n";

  std::cout << "Version 2" << "\n";
  encryptedString = CaesarCipher_2(theString, 5, true);
  decryptedString = CaesarCipher_2(encryptedString, 5, false);
  std::cout << "Input string: " << theString << "\n";
  std::cout << "Encrypted: " << encryptedString << "\n";
  std::cout << "Decrypted: " << decryptedString << "\n";

  return 0;
}

std::string CaesarCipher(std::string theString, int key, bool encrypt) {

  std::string retVal = "";

  for (auto c: theString) {
    retVal += (char) encrypt ? c - key : c + key;
  }

  return retVal;
}

// Derek's solution
std::string CaesarCipher_2(std::string theString, int key, bool encrypt) {
  std::string retVal = "";
  char letter;
  int charCode;

  if (encrypt) key *= -1;

  for (char& c: theString) {
    if (isalpha(c)) {
      charCode = c + key;

      if (isupper(c)) {
        if (charCode > (int)'Z') {
          charCode -= 26;
        } else if (charCode < (int)'A') {
          charCode += 26;
        }
      } else {
        if (charCode > (int)'z') {
          charCode -= 26;
        } else if (charCode < (int)'a') {
          charCode += 26;
        }
      }

      letter = charCode;
    } else {
      letter = c;
    }

    retVal += letter;
  }

  return retVal;
}