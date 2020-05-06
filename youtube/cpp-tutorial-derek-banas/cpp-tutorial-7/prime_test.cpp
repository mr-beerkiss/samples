#include <iostream>
#include <string>
#include <vector>

bool IsPrime(int num);
std::vector<int> GetPrimes(int maxPrimes);

int main(int argc, char *argv[])
{

  int maxPrimes = stoi(std::string(argv[1]));

  std::vector<int> primeList = GetPrimes(maxPrimes);

  // for (auto prime : primeList)
  // {
  //   std::cout << prime << " ";
  // }

  // std::cout << "\n";

  std::cout << "Found " << primeList.size() << " primes!\n";

  return 0;
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

std::vector<int> GetPrimes(int maxPrimes)
{
  std::vector<int> results;

  if (maxPrimes > 0)
    results.push_back(1);

  if (maxPrimes > 2)
  {
    int foundPrimes = 2;
    int next = 3;
    while (foundPrimes <= maxPrimes)
    {
      if (IsPrime(next))
      {
        results.push_back(next);
        foundPrimes++;
      }
      next += 2;
    }
  }

  return results;
}