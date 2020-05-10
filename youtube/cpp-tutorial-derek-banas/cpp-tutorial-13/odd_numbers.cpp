#include <vector>
#include <iostream>
#include <string>

/* 
Function that receives a list and a function

The passed function should return true/false if a value is odd

The surround function should return a list of odd numbers
*/

bool isOdd(int num);
std::string VecToString(std::vector<int> theVector, std::string separator);
std::vector<int> Range(int start, int end, int step);
std::vector<int> GenerateRandVec(int amount, int min, int max);

std::vector<int> filterList(std::vector<int>, std::function<bool(int)>);

int main()
{

  std::vector<int> randInts = GenerateRandVec(20, 1, 100);

  std::sort(randInts.begin(), randInts.end(), [](int num1, int num2) { return num1 < num2; });

  std::vector<int> filteredRands = filterList(randInts, isOdd);

  std::cout << "Generated List: " << VecToString(randInts, ", ") << "\n";
  std::cout << "Filtered List : " << VecToString(filteredRands, ", ") << "\n";

  return 0;
}

bool isOdd(int num)
{
  return num % 2 != 0;
}

std::vector<int> filterList(std::vector<int> list, std::function<bool(int)> filterFunc)
{
  std::vector<int> filteredList;

  for (int num : list)
  {
    if (filterFunc(num))
    {
      filteredList.push_back(num);
    }
  }

  return filteredList;
}

std::string VecToString(std::vector<int> theVector, std::string separator)
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