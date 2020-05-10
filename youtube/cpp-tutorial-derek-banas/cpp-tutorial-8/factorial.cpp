#include <iostream>

int Factorial(int number);

int main()
{
  int factorial3 = Factorial(10);

  std::cout << "[CPP] Factorial(3) = " << factorial3 << "\n";
}

int Factorial(int number)
{
  if (number == 1)
    return 1;
  return number * Factorial(number - 1);
}