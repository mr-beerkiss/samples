#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <random>

#define MAX_DIFFICULTY 10

const int CODES = 3;

bool PlayGameWithDifficulty(int difficulty)
{
  std::random_device r;
  std::default_random_engine randEng(r());
  std::uniform_int_distribution<int> uniform_dist(1, difficulty);

  std::vector<int> codes;

  for (int i = 0; i < CODES; i++)
  {
    // codes.push_back(std::rand() % difficulty + difficulty);
    codes.push_back(uniform_dist(randEng));
  }

  int codeSum = 0, codeProduct = 1;

  std::for_each(codes.begin(), codes.end(), [&codeProduct, &codeSum](int x) {
    codeSum += x;
    codeProduct *= x;
  });

  std::cout << "You need to guess three numbers." << std::endl;
  std::cout << "The sum of the three numbers is " << codeSum << std::endl;
  std::cout << "The product of the three numbers is " << codeProduct << std::endl;

  std::string guessStrA, guessStrB, guessStrC;

  std::cout << "Enter numbers: ";
  std::cin >> guessStrA >> guessStrB >> guessStrC;

  // std::stringstream ss(guessStr);
  // std::string stringPart;
  std::vector<int> guesses;

  // while (getline(ss, stringPart, ' '))
  guesses.push_back(std::stoi(guessStrA));
  guesses.push_back(std::stoi(guessStrB));
  guesses.push_back(std::stoi(guessStrC));

  std::cout << "Number of guesses: " << guesses.size() << "\n";

  for (auto i : guesses)
  {
    std::vector<int>::iterator it = std::find(codes.begin(), codes.end(), i);
    if (it != codes.end())
    {
      codes.erase(it);
      std::cout << i << " is a correct guess\n";
    }
    else
    {
      std::cout << "Bad guess\n";
      return false;
    }
  }

  return true;
}

int main()
{
  std::cout.flush();
  system("clear");
  std::cout << "You have awoken in a strange room. You do not remember how you got here. "
               "You notice a faint glow a few feet away. You feel weak, and cannot stand up."
               "You crawl over to the glow. As you approach the glow you recognise the the "
               "silhouette of very old computer.\n";

  int difficulty = 2;

  while (difficulty < MAX_DIFFICULTY)
  {
    if (!PlayGameWithDifficulty(difficulty))
    {
      std::cout << "You died!\n";
      break;
    }
    std::cin.clear();  // clears the failbit
    std::cin.ignore(); // discards the buffer
    difficulty++;
  }

  // PlayGameWithDifficulty(difficulty);

  std::cout << "GAME OVER\n";

  return 0;
}