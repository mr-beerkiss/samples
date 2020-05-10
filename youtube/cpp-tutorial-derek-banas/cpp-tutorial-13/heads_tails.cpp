#include <vector>
#include <iostream>
#include <random>

/* 
generate 100 coin flips and then display the number of heads and the number of tails
*/
enum CoinToss
{
  HEADS,
  TAILS
};

std::vector<CoinToss> GenerateCoinTosses(int amount);

int main()
{

  std::vector<CoinToss> coinFlips = GenerateCoinTosses(100);
  int heads, tails;

  std::for_each(coinFlips.begin(), coinFlips.end(), [&heads, &tails](CoinToss t) {
    if (t == CoinToss::HEADS)
      heads++;
    else
      tails++;
  });

  printf("Total numer of heads = %d; tails = %d\n", heads, tails);

  return 0;
}

std::vector<CoinToss> GenerateCoinTosses(int amount)
{
  std::vector<CoinToss> tosses;

  // Use c++11 features to generate _better_ random numbers than the old c version
  // Seed with a real random value, if available (what if it's not?)
  std::random_device r;

  // Choose a random number between and 0 and 1
  std::default_random_engine e1(r());
  std::uniform_int_distribution<int> uniform_dist(0, 1);

  for (int i = 0; i < amount; i++)
  {
    tosses.push_back(uniform_dist(e1) == 0 ? CoinToss::HEADS : CoinToss::TAILS);
  }

  return tosses;
}