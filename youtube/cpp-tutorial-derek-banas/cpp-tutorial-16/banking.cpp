#include <chrono>
#include <ctime>
#include <mutex>
#include <thread>
#include <iostream>

int GetRandom(int max)
{
  srand(time(NULL));
  return rand() % max;
}

std::string GetTime()
{
  auto nowTime = std::chrono::system_clock::now();
  std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);
  return std::ctime(&sleepTime);
}

double accBalance = 100;

std::mutex accLock;

void GetMoney(int id, double withdrawal)
{
  std::lock_guard<std::mutex> lock(accLock);
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::cout << "Thread " << id << " tries to withdraw " << withdrawal << " on " << GetTime() << "\n";

  if (accBalance - withdrawal >= 0)
  {
    accBalance -= withdrawal;
    std::cout << "New account balance is $" << accBalance << "\n";
  }
  else
  {
    std::cout << "Not enough money in Account\n";
    std::cout << "Current balance is $" << accBalance << "\n";
  }
}

int main()
{
  std::thread threads[10];
  for (int i = 0; i < 10; i++)
  {
    threads[i] = std::thread(GetMoney, i, 15);
  }
  for (int i = 0; i < 10; i++)
  {
    threads[i].join();
  }
}
