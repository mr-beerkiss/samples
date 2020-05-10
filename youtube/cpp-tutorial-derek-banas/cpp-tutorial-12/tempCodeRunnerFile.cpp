#include <string>
#include <iostream>
#include <sstream>

class Box
{
public:
  double length, width, breadth;
  std::string boxString;
  Box()
  {
    length = 1, width = 1, breadth = 1;
  }
  Box(double l, double w, double b)
  {
    length = l, width = w, breadth = b;
  }
  Box &operator++()
  {
    length++;
    width++;
    breadth++;
    return *this;
  }

  // Declaring a "const function" in this means it would result in compiler errors for this
  // method to attempt to modify members of the class
  double Volume() const
  {
    return length * width * breadth;
  }

  // A guess this is like an impicity `toString` function
  // Also not entirely sure what ostringstream does, or whether or not it cares about encoding
  operator const char *()
  {
    std::ostringstream boxStream;
    boxStream << "Box: " << length << ", " << width << ", " << breadth;
    boxString = boxStream.str();
    return boxString.c_str();
  }

  Box operator+(const Box &box2)
  {
    Box boxSum;
    boxSum.length = length + box2.length;
    boxSum.width = width + box2.width;
    boxSum.breadth = breadth + box2.breadth;
    return boxSum;
  }

  double operator[](int x)
  {
    if (x == 0)
    {
      return length;
    }
    else if (x == 1)
    {
      return width;
    }
    else if (x == 2)
    {
      return breadth;
    }
    else
    {
      return 0;
    }
  }

  bool operator==(const Box &box2)
  {
    if ((length == box2.length) && (width == box2.width) && (breadth == box2.breadth))
    {
      return true;
    }
    return false;
  }

  bool operator<(const Box &box2)
  {
    if (this->Volume() < box2.Volume())
    {
      return true;
    }

    return false;
  }

  bool operator>(const Box &box2)
  {
    if (this->Volume() > box2.Volume())
    {
      return true;
    }

    return false;
  }

  void operator=(const Box &boxToCopy)
  {
    length = boxToCopy.length;
    width = boxToCopy.width;
    breadth = boxToCopy.breadth;
  }
};

int main()
{

  std::cout.setf(std::ios::boolalpha);

  Box box(10, 10, 10);
  ++box;

  std::cout << box << "\n";

  Box box2(5, 5, 5);

  std::cout << "box1 + box2 = " << box + box2 << "\n";

  Box box3 = box2;

  printf("box 3 length = %.2f, width = %.2f and breadth = %.2f", box3[0], box3[1], box3[2]);

  std::cout << "Is box3 equal to box2: " << (box3 == box2) << "\n";

  return 0;
}