#include <iostream>

template <typename T, typename U>
class Person
{
public:
  T height;
  U weight;
  static int numOfPeople;
  Person(T h, U w)
  {
    height = h, weight = w;
    numOfPeople++;
  }
  void GetData()
  {
    std::cout << "Height : " << height << " and Weight: " << weight << "\n";
  }
};

template <typename T, typename U>
int Person<T, U>::numOfPeople;

int main()
{
  Person<double, int> mikeTyson(5.83, 216);
  mikeTyson.GetData();

  std::cout << "Number of People: " << mikeTyson.numOfPeople << "\n";

  Person<int, int> darren(180, 90);
  darren.GetData();
  // std::cout << "Number of People: " << darren.numOfPeople << "\n";

  Person<int, int> courtney(179, 66);
  courtney.GetData();
  // statics for a class are bound to the specific combination on template params they take
  // in the video he says you use the member field to access it which feels weird.
  // Alternatively, you can use the `::` class syntax and specify the types and it _should_ work
  std::cout << "Number of People: " << Person<int, int>::numOfPeople << "\n";
}