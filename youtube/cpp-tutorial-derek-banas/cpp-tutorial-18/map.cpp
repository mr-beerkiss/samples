#include <iostream>
#include <map>
#include <string>

int main()
{

  std::map<int, std::string> map1;
  map1.insert(std::pair<int, std::string>(1, "Bart"));
  map1.insert(std::pair<int, std::string>(2, "Lisa"));
  map1.insert(std::pair<int, std::string>(3, "Marge"));
  map1.insert(std::pair<int, std::string>(4, "Homer"));

  auto match = map1.find(1);
  std::cout << "Found: " << match->second << "\n";

  auto bart = map1.lower_bound(1);
  std::cout << "LB: " << bart->second << "\n";

  auto lisa = map1.upper_bound(1);
  std::cout << "UB: " << lisa->second << "\n";

  std::map<int, std::string>::iterator it2;

  for (it2 = map1.begin(); it2 != map1.end(); ++it2)
  {
    std::cout << "Key: " << it2->first << "\n";
    std::cout << "Value: " << it2->second << "\n";
  }

  return 0;
}