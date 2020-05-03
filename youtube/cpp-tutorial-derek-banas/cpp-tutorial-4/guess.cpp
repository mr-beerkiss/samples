#include <iostream>
#include <vector>
#include <ctime>

int main() {

  srand(time(NULL));
  int secretNum = std::rand() % 11;
  int guess = 0;

  do {
    std::cout << "Guess the number: ";
    std::cin >> guess;

    if (guess > secretNum) std::cout << "Guess too high!\n";
    else if (guess < secretNum) std::cout << "Guess too low!\n";
  } while (guess != secretNum);

  std::cout << "You got it! WELL DONE!\n";
  return 0;
}