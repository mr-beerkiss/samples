#include <map>
#include <iostream>

#include <string>

int main()
{

  std::multimap<int, std::string> mmap1;
  mmap1.insert(std::pair<int, std::string>(1, "Bart"));
  mmap1.insert(std::pair<int, std::string>(1, "Lisa"));
  mmap1.insert(std::pair<int, std::string>(3, "Marge"));

  std::map<int, std::string>::iterator it2;

  for (it2 = mmap1.begin(); it2 != mmap1.end(); ++it2)
  {
    std::cout << "Key: " << it2->first << "\n";
    std::cout << "Value: " << it2->second << "\n";
  }

  return 0;
}