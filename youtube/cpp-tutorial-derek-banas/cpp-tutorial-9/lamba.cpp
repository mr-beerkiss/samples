#include <vector>
#include <iostream>
#include <string>

std::vector<int> GenerateRandVec(int amount, int min, int max);
std::vector<int> Range(int start, int end, int step);
std::string VecToString(std::vector<int> theVector, std::string separator);
bool IsPrime(int num);

int main()
{

  std::vector<int> vecVals = GenerateRandVec(25, 1, 100);

  std::cout << "Unsorted vec = " << VecToString(vecVals, ", ") << "\n";
  std::sort(vecVals.begin(), vecVals.end(), [](int x, int y) { return x < y; });
  std::cout << "Sorted vec = " << VecToString(vecVals, ", ") << "\n";

  int sum = 0;
  std::for_each(vecVals.begin(), vecVals.end(), [&](int x) { sum += x; });
  std::cout << "Sum of vec = " << sum << "\n";

  int product = 1;
  // NOTE: Use [&] to allow the lambda access to variables defined in the enclosing scope
  std::for_each(vecVals.begin(), vecVals.end(), [&](int x) { product *= x; });
  std::cout << "Product of vec = " << product << "\n";

  int difference = 0;
  std::for_each(vecVals.begin(), vecVals.end(), [&](int x) { difference -= x; });
  std::cout << "Difference of vec = " << difference << "\n";

  std::vector<int> evenVecVals;
  std::vector<int> vecPrimes;

  std::copy_if(vecVals.begin(), vecVals.end(), std::back_inserter(evenVecVals), [](int x) { return x % 2 == 0; });
  std::copy_if(vecVals.begin(), vecVals.end(), std::back_inserter(vecPrimes), [](int x) { return IsPrime(x); });

  // Note the `[](..args)` syntax denotes a lambda function

  // std::sort(evenVecVals.begin(), evenVecVals.end(), [](int x, int y) { return x < y; });

  std::cout << "Even vec vals (Sorted) = " << VecToString(evenVecVals, ", ") << "\n";
  std::cout << "Prime vec vals (Sorted) = " << VecToString(vecPrimes, ", ") << "\n";

  return 0;
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
