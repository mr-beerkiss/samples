#include <iostream>
#include <vector>
#include <ctime>

std::vector<int> Range(int start, int end, int step);
std::vector<int> GenerateRandVec(int amount, int min, int max);

void BubbleSort(std::vector<int> &theVec);

int main()
{
  std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
  BubbleSort(vecVals);

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

void BubbleSort(std::vector<int> &theVec)
{
  int i = theVec.size() - 1;

  while (i >= 1)
  {
    int j = 0;

    while (j < i)
    {
      printf("\nIs %d > %d\n", theVec[j], theVec[j + 1]);

      if (theVec[j] >= theVec[j + 1])
      {
        std::cout << "Switch\n";

        int temp = theVec[j];
        theVec[j] = theVec[j + 1];
        theVec[j + 1] = temp;
      }
      else
      {
        std::cout << "Don't switch\n";
      }
      j += 1;

      for (auto k : theVec)
      {
        std::cout << k << ", ";
      }
    }
    std::cout << "\nEnd of Round\n";
    i -= 1;
  }
}