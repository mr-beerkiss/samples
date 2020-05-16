#include <iostream>
#include <list>

bool isEven(const int &val)
{
  return val % 2 == 0;
}

int main()
{

  int arr[5] = {1, 2, 3, 4, 5};
  std::list<int> list1;
  list1.insert(list1.begin(), arr, arr + 5);
  // list1.assign({10, 20, 30});

  list1.push_back(5);
  list1.push_front(1);

  std::cout << "Size = " << list1.size() << "\n";

  // std::cout << "list1[0] = " << list1[0] << "\n";
  std::list<int>::iterator it2 = list1.begin();
  std::advance(it2, 1);
  std::cout << "2nd Index = " << *it2 << "\n";

  it2 = list1.begin();
  list1.insert(it2, 8);
  it2 = list1.begin();
  list1.erase(list1.begin());

  it2 = list1.begin();
  std::list<int>::iterator it3 = list1.begin();
  std::advance(it3, 2);
  // erase using to iterators
  list1.erase(it2, it3);

  list1.pop_back();
  list1.pop_front();

  int arr2[6] = {10, 9, 8, 7, 6, 6};
  std::list<int> list2;
  list2.insert(list2.begin(), arr2, arr2 + 6);
  list2.sort();
  list2.reverse();
  list2.unique();
  list2.remove(6);
  list2.remove_if(isEven);
  list1.merge(list2);

  for (const auto &i : list1)
  {
    std::cout << i << "\n";
  }

  std::cout << "list 2\n";

  for (const auto &i : list2)
  {
    std::cout << i << "\n";
  }

  return 0;
}