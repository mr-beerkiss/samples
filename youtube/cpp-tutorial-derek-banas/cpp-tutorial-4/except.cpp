#include <iostream>

int main() {
  double num1 = 0, num2 = 0;

  std::cout << "Enter number 1 : ";
  std::cin >> num1;

  std::cout << "Enter number 2 : ";
  std::cin >> num2;

  try {
    if(num2 == 0) {
      throw "Division by zero in not possible";
    } else {
      printf("%.1f / %.1f = %.2f\n", num1, num2, (num1/num2));
    }
  } catch (const char* ex) {
    std::cerr << "Error: " << ex << "\n";
  }
}