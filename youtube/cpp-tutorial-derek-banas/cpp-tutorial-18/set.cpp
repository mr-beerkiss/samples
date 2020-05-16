#include <iostream>
#include <set>

int main()
{

  std::set<int> set1{5, 4, 3, 2, 1, 1};

  std::cout << "Size: " << set1.size() << "\n";

  set1.insert(0);

  std::set<int>::iterator it = set1.begin();
  it++;
  std::cout << "2nd value: " << *it << "\n";

  set1.erase(5);

  it = set1.end();
  std::advance(it, -2);

  set1.erase(it, set1.end());

  int arr[] = {6, 7, 8, 9};
  set1.insert(arr, arr + 4);

  auto val = set1.find(6);
  std::cout << "Found: " << *val << "\n";

  auto eight = set1.lower_bound(8);
  std::cout << "Eight: " << *eight << "\n";

  auto nine = set1.upper_bound(9);
  std::cout << "Nine: " << *nine << "\n";

  std::set<int> set2{10, 11};

  set1.swap(set2);

  if (!set1.empty())
  {
    for (int i : set1)
    {
      std::cout << i << "\n";
    }
  }

  return 0;
}