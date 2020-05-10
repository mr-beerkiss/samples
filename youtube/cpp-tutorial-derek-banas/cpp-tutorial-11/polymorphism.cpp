#include <iostream>
#include <cmath>

class Shape
{
public:
  virtual double Area() = 0;
};

class Circle : public Shape
{
protected:
  double radius;

public:
  Circle(double r)
  {
    radius = r;
  }

  double Area() override
  {
    return 3.14159 * std::pow(radius, 2);
  }
};

class Rectangle : public Shape
{
protected:
  double width, length;

public:
  Rectangle(double w, double l)
  {
    width = w;
    length = l;
  }

  double Area() override final
  {
    return width * length;
  }
};

class Square : public Rectangle
{
public:
  Square(double length) : Rectangle(length, length)
  {
  }

  // area in Rectangle is `final`
  // double Area() override
  // {
  //   return length * length;
  // }
};

void ShowArea(Shape &shape)
{
  std::cout << "Area: " << shape.Area() << "\n";
}

int main()
{
  Rectangle rect(10, 15);
  Circle circle(10);
  Square square(12);
  ShowArea(rect);
  ShowArea(circle);
  ShowArea(square);

  return 0;
}