#include <iostream>
#include <string>

void PrintRow(int size);

int main()
{

  int arr[] = {10, 8, 2};
  int size = sizeof(arr) / sizeof(int);

  PrintRow(size);
  for (int i = 0; i < size; ++i)
  {
    // if (i < 10)
    // {
    //   printf("|  %d  ", i);
    // }
    // else if (i < 100)
    // {
    //   printf("| %d  ", i);
    // }
    // else
    // {
    //   printf("| %d ", i);
    // }
    printf("| %2d  ", i);
  }
  std::cout << "|\n";
  PrintRow(size);
  for (auto el : arr)
  {
    // if (el < 10)
    // {
    //   printf("|  %d  ", el);
    // }
    // else if (el < 100)
    // {
    //   printf("| %d  ", el);
    // }
    // else
    // {
    //   printf("| %d ", el);
    // }
    printf("| %2d  ", el);
  }
  std::cout << "|\n";
  PrintRow(size);

  return 0;
}

const std::string ROW_STRING = "------";

void PrintRow(int size)
{
  int i = 0;
  while (i < size)
  {
    i++;
    std::cout << ROW_STRING;
  }
  std::cout << "\n";
}
