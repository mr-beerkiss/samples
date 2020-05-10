#include <iostream>

int Fib(int index);

int main()
{
  int index;
  std::cout << "Enter Fibonacci Index: ";
  std::cin >> index;

  printf("Fib(%d) = %d\n", index, Fib(index));

  return 0;
}

int Fib(int index)
{
  if (index < 2)
    return index;

  return Fib(index - 1) + Fib(index - 2);
}