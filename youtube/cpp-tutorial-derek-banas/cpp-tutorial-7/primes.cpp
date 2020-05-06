#include <iostream>
#include <string>
#include <vector>

bool IsPrime(int num);
std::vector<int> GetPrimes(int maxPrimes);

int main()
{

  // this will print booleans as `true` or `false` instead of `1` or `0`
  std::cout.setf(std::ios::boolalpha);

  int num = 0;
  std::cout << "Number to check: ";
  std::cin >> num;

  std::cout << "Is " << num << " Prime? " << IsPrime(num) << "\n";

  int maxPrimes;
  std::cout << "Generate primes up to ";
  std::cin >> maxPrimes;

  std::vector<int> primeList = GetPrimes(maxPrimes);

  for (auto prime : primeList)
  {
    std::cout << prime << " ";
  }

  std::cout << "\n";

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

  if (maxPrimes > 1)
    results.push_back(2);

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