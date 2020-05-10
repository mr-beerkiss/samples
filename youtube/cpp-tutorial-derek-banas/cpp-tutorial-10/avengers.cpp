#include <ctime>
#include <string>
#include <iostream>

class Warrior
{
private:
  std::string name;
  int health;
  int attack;
  int block;
  bool dead = false;

public:
  std::string GetName() { return name; }
  int GetHealth() { return health; }
  // int SetHealth(int health) { this->health = health; }
  // int GetAttack() { return attack; }
  // int GetBlock() { return block; }
  bool IsDead() { return dead; }

  int Attack();
  int Block();

  void TakeDamage(int);

  Warrior(std::string, int, int, int);
};

Warrior::Warrior(std::string name, int health, int attack, int block)
{
  this->name = name;
  this->health = health;
  this->attack = attack;
  this->block = block;
}

void Warrior::TakeDamage(int damage)
{
  this->health -= damage;
  if (this->health <= 0)
  {
    this->health = 0;
    this->dead = true;
  }
}

int Warrior::Attack()
{
  return std::rand() % this->attack;
}

int Warrior::Block()
{
  return std::rand() % this->block;
}

class Battle
{
public:
  static void StartFight(Warrior &, Warrior &);
};

void Battle::StartFight(Warrior &defender, Warrior &attacker)
{
  while (true)
  {
    int damage = attacker.Attack();
    int block = defender.Block();
    int actualDamage = (damage - block > 0) ? damage - block : 0;

    // int damage = std::rand() % (1 + maxDmg - minDmg) + minDmg;

    defender.TakeDamage(actualDamage);

    std::cout << attacker.GetName() << " attacks " << defender.GetName()
              << " and deals " << damage << " damage\n";
    std::cout << defender.GetName() << " is down to " << defender.GetHealth() << "\n";

    if (defender.IsDead())
    {
      std::cout << defender.GetName() << " has died and " << attacker.GetName()
                << " is victorious\n";
      std::cout << "Game Over\n";
      break;
    }

    auto tmp = attacker;
    attacker = defender;
    defender = tmp;
  }
}

int main()
{
  srand(time(NULL));

  // name, hp, attack, block
  Warrior thor("Thor", 100, 30, 15);
  Warrior hulk("Hulk", 135, 25, 10);

  Battle::StartFight(thor, hulk);

  return 0;
}