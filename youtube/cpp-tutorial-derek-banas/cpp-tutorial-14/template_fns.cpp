#include <iostream>

#define PI 3.14159
// aka the golden ratio
#define PHI 1.61803398875

template <typename T>
void Times2(T val)
{
  std::cout << val << " * 2 = " << val * 2 << "\n";
}

template <typename T>
T Add(T val, T val2)
{
  return val + val2;
}

template <typename T>
T Max(T val, T val2)
{
  return (val > val2) ? val : val2;
}

int main()
{
  Times2(5);
  Times2(5.3);

  std::cout << "3 + 4 = " << Add(3, 4) << "\n";
  std::cout << "PI + PHI = " << Add(PI, PHI) << "\n";

  std::cout << "Max(3, 4) = " << Max(3, 4) << "\n";
  std::cout << "Max(A, B) = " << Max('A', 'B') << "\n";
  std::cout << "Max(PI, PHI) = " << Max(PI, PHI) << "\n";
  std::cout << "Max(Dog, Cat) = " << Max("Dog", "Cat") << "\n";
}