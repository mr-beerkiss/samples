#include <iostream>
#include <cmath>

const double PI = 3.14150;

double Area(double radius);
double Area(double height, double width);

int main()
{
  std::cout << "Area (c) or Rectangle (r): ";
  char areaType;
  std::cin >> areaType;

  switch (areaType)
  {
  case 'c':
    // NB: There is some really weird shit in C++ that happens when you try declare vars inside
    // of case statements. Theere is description of why [here](https://forums.whirlpool.net.au/archive/1794875).
    // Comment out the code below to the see the errors
    // double radius;
    std::cout << "Enter circle radius: ";
    double radius;
    std::cin >> radius;
    // double circleArea = Area(radius);
    printf("Area of circle with radius %.2f = %.2f\n", radius, Area(radius));
    break;
  case 'r':
    // double width, height;
    std::cout << "Enter rectangle width: ";
    double width, height;
    std::cin >> width;
    std::cout << "Enter rectangle height: ";
    std::cin >> height;
    // double rectArea = Area(width, height);
    printf("Area of rectable with width %.2f and height %.2f = %.2f\n", width, height, Area(width, height));
    break;
  default:
    std::cout << "Unknown type " << areaType << "\n";
  }

  return 0;
}

double Area(double radius)
{
  return PI * std::pow(radius, 2);
}

double Area(double height, double width)
{
  return height * width;
}
