#include <deque>
#include <iostream>

bool isEven(const int &val)
{
  return (val % 2 == 0);
}

int main()
{
  std::deque<int> deq1;
  deq1.assign({11, 12});
  deq1.push_back(5);
  deq1.push_front(1);

  std::cout << "Size: " << deq1.size() << "\n";
  std::cout << "deq1[0] = " << deq1[0] << "\n";
  std::cout << "deq1.at(1) = " << deq1.at(1) << "\n";

  // use an iterator to insert
  std::deque<int>::iterator it = deq1.begin() + 1;
  deq1.insert(it, 3);

  int tempArr[5] = {6, 7, 8, 9, 10};
  deq1.insert(deq1.end(), tempArr, tempArr + 5);
  deq1.erase(deq1.end());
  deq1.erase(deq1.begin(), deq1.begin() + 2);

  deq1.pop_front();
  deq1.pop_back();

  std::deque<int> deq2(2, 50);
  deq1.swap(deq2);

  deq1.clear();

  for (auto i : deq1)
  {
    std::cout << i << "\n";
  }

  return 0;
}