#include "util.h"

std::vector<int> Range(int start, int end, int step)
{
  std::vector<int> range;

  for (int i = start; i < end; ++i)
  {
    range.push_back(i);
  }

  return range;
}

std::vector<int> GenerateRandVec(int amount, int min, int max)
{
  std::vector<int> randoms;
  srand(time(NULL));

  for (auto _ : Range(0, amount, 1))
  {
    randoms.push_back((std::rand() % (1 + max - min)) + min);
  }

  return randoms;
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

std::string VecToString(std::vector<std::string> theVector, char separator)
{
  std::string theString = "";
  for (auto i = 0; i < theVector.size(); ++i)
  {
    theString += theVector[i];
    if (i < theVector.size() - 1)
      theString += separator;
  }

  return theString;
}

std::string VecToString(std::vector<int> theVector, char separator);
std::string VecToString(std::vector<int> theVector, char separator)
{
  std::string theString = "";

  for (auto i = 0; i < theVector.size(); ++i)
  {
    theString += std::to_string(theVector[i]);
    if (i < theVector.size() - 1)
      theString += separator;
  }

  return theString;
}

bool IsPrime(int num)
{
  if (num < 4)
    return true;

  if (num % 2 == 0)
    return false;

  for (auto d = num - 1; d > 2; --d)
    if (num % d == 0)
      return false;

  return true;
}

int Factorial(int number)
{
  if (number == 1)
    return 1;
  return number * Factorial(number - 1);
}

int Fib(int index)
{
  if (index < 2)
    return index;

  return Fib(index - 1) + Fib(index - 2);
}
