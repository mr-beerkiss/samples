#include <iostream>
#include <string>
#include <vector>

std::string VecToString(std::vector<int> theVector, std::string separator);
std::vector<int> GenerateRandVec(int amount, int min, int max);
std::vector<int> Range(int start, int end, int step);

int main()
{
  std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
  std::sort(vecVals.begin(), vecVals.end(), [](int x, int y) { return x > y; });

  int divisor;
  std::vector<int> vecVals2;
  std::cout << "List of values divisible by: ";
  std::cin >> divisor;

  std::copy_if(vecVals.begin(), vecVals.end(), std::back_inserter(vecVals2), [divisor](int x) { return x % divisor == 0; });

  std::cout << "List of values divisible by " << divisor << ": " << VecToString(vecVals2, ", ") << "\n";

  std::vector<int> guaranteedDiv;

  std::for_each(vecVals.begin(), vecVals.end(), [&](int x) {
    if (x % divisor == 0)
    {
      guaranteedDiv.push_back(x);
    }
    else
    {
      guaranteedDiv.push_back(x * divisor % 50);
    }
  });

  std::cout << "\nList 1: " << VecToString(vecVals, ", ") << "\n";
  std::cout << "List 2:  " << VecToString(guaranteedDiv, ", ") << "\n\n";

  std::vector<int> doubleVec;

  std::for_each(vecVals.begin(), vecVals.end(), [&](int x) { doubleVec.push_back(x * 2); });
  std::cout << "Doubled values: " << VecToString(doubleVec, ", ") << "\n";

  return 0;
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
