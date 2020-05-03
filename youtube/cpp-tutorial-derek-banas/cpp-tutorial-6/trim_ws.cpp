#include <string>
#include <iostream>
#include <vector>

std::string TrimWhitespace(std::string theString);
std::vector<int> FindWordBoundaries(std::string thString);
std::vector<int> FindSubstringMatches(std::string theString, std::string match);
std::string FindAndReplaceAll(std::string theString, std::string match, std::string replacement);

int main() {

  std::string aString = "      Just some random words       ";
  aString = TrimWhitespace(aString);

  std::cout << "*" << aString << "*\n";

  std::vector<int> indexes = FindWordBoundaries(TrimWhitespace("Hi I am Darren"));

  std::cout << "Indexes = ";
  for (auto i: indexes) std::cout << i << ",";
  std::cout << "\n";

  std::vector<int> matches = FindSubstringMatches("To be or not to be", "be");
  std::cout << "Matches = ";
  for (auto m: matches) std::cout << m << ",";
  std::cout << "\n";


  std::string replacedString = FindAndReplaceAll("To be or not to be", "be", "exist");
  std::cout << "Replaced String = " << replacedString << "\n";



  return 0;
}

std::string TrimWhitespace(std::string theString) {
  std::string whitespaces(" \t\f\n\r");
  theString.erase(theString.find_last_not_of(whitespaces) + 1);
  theString.erase(0, theString.find_first_not_of(whitespaces));
  return theString;
}



std::vector<int> FindWordBoundaries(std::string theString) {
  std::vector<int> indexes;
  std::string space = " ";

  int nextIndex = 0;

  while (nextIndex != std::string::npos) {
    indexes.push_back(nextIndex++);
    nextIndex = theString.find(space, nextIndex);
  }

  return indexes;
}

std::string FindAndReplaceAll(std::string theString, std::string match, std::string replacement) {
  auto matches = FindSubstringMatches(theString, match);

  int nextIndex = theString.find(match);

  while (nextIndex != std::string::npos) {
    theString.replace(nextIndex, match.length(), replacement);
    nextIndex = theString.find(match, nextIndex+1);
  }

  return theString;
}

std::vector<int> FindSubstringMatches(std::string theString, std::string match) {
  std::vector<int> indexes;

  int nextIndex = theString.find(match);

  while (nextIndex != std::string::npos) {
    indexes.push_back(nextIndex++);
    nextIndex = theString.find(match, nextIndex);
  }

  return indexes;
}