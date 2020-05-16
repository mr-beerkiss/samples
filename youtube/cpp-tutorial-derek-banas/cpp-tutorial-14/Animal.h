#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
public:
  Animal();
  Animal(const Animal &org);
  virtual ~Animal();
  std::string name;

private:
};

#endif /* ANIMAL_H */
