#include <iostream>
#include <queue>
#include <string>

int main()
{
  std::queue<std::string> cast;
  cast.push("Zoidberg");
  cast.push("Bender");
  cast.push("Leela");

  int size = cast.size();

  if (!cast.empty())
  {
    for (int i = 0; i < size; i++)
    {
      std::cout << cast.front() << "\n";
      cast.pop();
    }
  }

  return 0;
}
