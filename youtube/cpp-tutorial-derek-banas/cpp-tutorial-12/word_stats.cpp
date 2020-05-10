#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

std::vector<std::string> StringToVec(std::string theString, char separator);

int main()
{

  std::string nextLine;
  std::vector<std::string> words;
  std::ifstream readStream;

  readStream.open("test.txt", std::ios_base::in);
  if (readStream.is_open())
  {
    while (readStream.good())
    {
      getline(readStream, nextLine);
      std::vector<std::string> lineWords = StringToVec(nextLine, ' ');
      words.insert(words.end(), lineWords.begin(), lineWords.end());
    }
    readStream.close();

    int wordCount = words.size();
    int totalWordLength = 0;

    for (auto word : words)
    {
      totalWordLength += word.length();
    }

    printf("Total words = %d. Avg word length %.2f\n", wordCount, ((double)totalWordLength / (double)wordCount));
  }

  return 0;
}

std::vector<std::string> StringToVec(std::string theString, char separator)
{
  std::vector<std::string> vecsWords;

  std::stringstream ss(theString);
  std::string sIndviStr;

  while (getline(ss, sIndviStr, separator))
    vecsWords.push_back(sIndviStr);

  return vecsWords;
}