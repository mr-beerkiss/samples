#include <iostream>
#include <string>
#include <vector>

std::vector<int> GenerateFibList(int size);
std::vector<int> GenerateFibList_2(int size);
std::string VecToString(std::vector<int> theVector, std::string separator);
std::vector<int> Range(int start, int end, int step);

int main()
{
  int numFibs;
  std::cout << "How many Fibonacci numbers would you like to generate: ";
  std::cin >> numFibs;

  std::vector<int> listOfFibs = GenerateFibList(numFibs);

  std::cout << "Fib list (v1): " << VecToString(listOfFibs, ", ") << "\n";

  std::vector<int> listOfFibs2 = GenerateFibList_2(numFibs);

  std::cout << "Fib list (v2): " << VecToString(listOfFibs, ", ") << "\n";
}

std::vector<int> GenerateFibList(int size)
{
  std::function<int(int)> Fib = [&Fib](int n) { return n < 2 ? n : Fib(n - 1) + Fib(n - 2); };
  std::vector<int> res;
  for (auto i = 0; i < size; i++)
  {
    res.push_back(Fib(i));
  }
  return res;
}

std::vector<int> GenerateFibList_2(int size)
{
  std::function<int(int)> Fib = [&Fib](int n) { return n < 2 ? n : Fib(n - 1) + Fib(n - 2); };
  std::vector<int> range = Range(0, size, 1);
  std::vector<int> res;

  std::for_each(range.begin(), range.end(), [&](int x) { res.push_back(Fib(x)); });
  return res;
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
