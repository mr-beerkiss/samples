#include <iostream>
#include <string>
#include <vector>

std::string VecToString(std::vector<int> theVector, std::string separator);
std::vector<int> GenerateRandVec(int amount, int min, int max);
std::vector<int> Range(int start, int end, int step);

int main()
{
  std::vector<int> vecVals = GenerateRandVec(10, 1, 50);

  std::vector<int> vec1 = {1, 2, 3, 4, 5};
  std::vector<int> vec2 = {1, 2, 3, 4, 5};
  std::vector<int> vec3(5);

  transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(), [](int x, int y) { return x + y; });
  std::cout << "Added vecs: " << VecToString(vec3, ", ") << "\n";

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
