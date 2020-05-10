#include <string>
#include <iostream>
#include <sstream>

class Animal
{
protected:
  std::string name;
  double height;
  double weight;

  static int numOfAnimals;

public:
  std::string GetName()
  {
    return name;
  }
  void SetName(std::string name)
  {
    this->name = name;
  }
  double GetHeight() { return height; }
  void SetHeight(double height) { this->height = height; }

  double GetWeight() { return weight; }
  void SetWeight(double weight) { this->weight = weight; }

  void SetAll(std::string, double, double);
  Animal(std::string, double, double);
  Animal();
  ~Animal();

  static int GetNumOfAnimals() { return numOfAnimals; }
  std::string ToString();
};

int Animal::numOfAnimals = 0;
void Animal::SetAll(std::string name, double height, double weight)
{
  this->name = name;
  this->height = height;
  this->weight = weight;
  Animal::numOfAnimals++;
}

Animal::Animal(std::string name, double height, double weight)
{
  this->name = name;
  this->height = height;
  this->weight = weight;
  Animal::numOfAnimals++;
}

Animal::Animal()
{
  this->name = "";
  this->height = 0;
  this->weight = 0;
  Animal::numOfAnimals++;
}

Animal::~Animal()
{
  std::cout << "Animal " << this->name << " destroyed\n";
}

std::string Animal::ToString()
{
  std::stringstream ss;
  ss << this->name << " is " << this->height << "cms tall and "
     << this->weight << "kgs in weight\n";
  return ss.str();
}

class Dog : public Animal
{
private:
  std::string sound = "Woof";

public:
  void MakeSound()
  {
    std::cout << "The dog " << this->GetName() << "says " << this->sound << "\n";
  }
  Dog(std::string, double, double, std::string);
  Dog() : Animal(){};

  std::string ToString();
};

Dog::Dog(std::string name, double height, double weight, std::string sound) : Animal(name, height, weight)
{
  this->sound = sound;
}

std::string Dog::ToString()
{
  std::stringstream ss;
  ss << this->name << " is " << this->height << "cms tall and "
     << this->weight << "kgs in weight and says " << this->sound << ".\n";
  return ss.str();
}

int main()
{

  Animal fred;

  std::cout << fred.ToString();

  fred.SetAll("Fred", 33, 10);

  std::cout << fred.ToString();

  Animal tom("Tom", 36, 15);

  std::cout << tom.ToString();

  Dog spot("Spot", 38, 16, "Wooooof");

  std::cout << spot.ToString();

  std::cout << "Number of animals created: " << Animal::GetNumOfAnimals() << "\n";

  return 0;
}