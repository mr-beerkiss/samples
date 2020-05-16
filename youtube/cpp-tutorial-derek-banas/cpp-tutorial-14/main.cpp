#include <iostream>
#include <cmath>
#include <vector>

#include "Animal.h"
#include "util.h"

#define PI 3.13159

#define AREA_CIRCLE(radius) (PI * (std::pow(radius, 2)))

// to compile with utils (finally got it)
// the `-I` flag indicates location for header files
// At the end list all the locations of cpp files you want compiled
// clang++ -std=c++14 -o main -I ../include *.cpp ../include/*.cpp

int main()
{

  Animal spot = Animal();
  spot.name = "Spot";

  std::cout << "The Animal is named: " << spot.name << "\n";
  std::cout << "Circle area: " << AREA_CIRCLE(5) << "\n";

  std::vector<int> randVales = GenerateRandVec(20, 1, 50);

  for (int i = 0; i < randVales.size(); i++)
  {
    if (i < randVales.size() - 1)
    {
      std::cout << i << ", ";
    }
    else
    {
      std::cout << i << "\n";
    }
  }

  return 0;
}