#include <iostream>
#include <queue>
#include <string>

int main()
{
  std::priority_queue<int> nums;
  nums.push(4);
  nums.push(8);
  nums.push(5);

  int size = nums.size();

  if (!nums.empty())
  {
    for (int i = 0; i < size; i++)
    {
      std::cout << nums.top() << "\n";
      nums.pop();
    }
  }

  return 0;
}
