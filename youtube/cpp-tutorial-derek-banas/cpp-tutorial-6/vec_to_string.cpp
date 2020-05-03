#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> StringToVec(std::string theString, char separator);

std::string VecToString(std::vector<std::string> theVector, char separator);

int main() {
  std::vector<std::string> vec= StringToVec("This is a random string", ' ');

  for (auto s: vec) std::cout << s << "\n";

  std::vector<std::string> vCusts(3);
  vCusts[0] = "Bob";
  vCusts[1] = "Sue";
  vCusts[2] = "Tom";

  std::string sCusts = VecToString(vCusts, ' ');
  std::cout << sCusts << "\n";

  return 0;
}

std::vector<std::string> StringToVec(std::string theString, char separator) {
  std::vector<std::string> vecsWords;

  std::stringstream ss(theString);
  std::string sIndviStr;
  
  while (getline(ss, sIndviStr, separator)) vecsWords.push_back(sIndviStr);

  return vecsWords;
}

std::string VecToString(std::vector<std::string> theVector, char separator) {
  std::string theString = "";

  // for (auto s: theVector) theString += s + separator;
  for (auto i=0; i < theVector.size(); ++i) {
    theString += theVector[i];
    if (i < theVector.size() - 1) theString += separator;
  }

  return theString;
}