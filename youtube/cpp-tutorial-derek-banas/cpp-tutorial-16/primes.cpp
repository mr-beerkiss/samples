#include <chrono>
#include <ctime>
#include <mutex>
#include <thread>
#include <iostream>
#include <vector>

std::mutex vecLock;
std::vector<unsigned int> primeVec;

void FindPrimes(unsigned int start, unsigned int end)
{
  for (unsigned int x = start; x <= end; x += 2)
  {
    for (unsigned int y = 2; y < x; y++)
    {
      if (x % y == 0)
      {
        break;
      }
      else if (y + 1 == x)
      {
        vecLock.lock();
        primeVec.push_back(x);
        vecLock.unlock();
      }
    }
  }
}

void FindPrimesWithThreads(unsigned int start, unsigned int end, unsigned int numThreads)
{
  std::vector<std::thread> threadVec;

  unsigned int threadSpread = end / numThreads;
  unsigned int newEnd = start + threadSpread - 1;
  for (unsigned x = 0; x < numThreads; x += 1)
  {
    threadVec.emplace_back(FindPrimes, start, newEnd);
    start += threadSpread;
    newEnd += threadSpread;
  }
  for (auto &t : threadVec)
  {
    t.join();
  }
}

int main()
{

  // std::vector<unsigned int> primeVec2
  // int startTime = clock();
  // FindPrimes(1, 100000);
  // for (auto i : primeVec)
  //   std::cout << i << ", ";
  // int endTime = clock();

  // std::cout << "\nExecution time: " << (endTime - startTime) / double(CLOCKS_PER_SEC) << std::endl;

  int startTime = clock();
  FindPrimesWithThreads(1, 250000, 3);
  for (auto i : primeVec)
    std::cout << i << ", ";
  int endTime = clock();

  std::cout << "\nExecution time: " << (endTime - startTime) / double(CLOCKS_PER_SEC) << std::endl;

  return 0;
}