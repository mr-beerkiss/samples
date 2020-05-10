#include <iostream>
#include <vector>
#include <ctime>

std::vector<int> Range(int start, int end, int step);
std::vector<int> GenerateRandVec(int amount, int min, int max);

int main()
{
  std::vector<int> vecVals = GenerateRandVec(10, 5, 50);
  for (auto x : vecVals)
    std::cout << x << "\n";
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