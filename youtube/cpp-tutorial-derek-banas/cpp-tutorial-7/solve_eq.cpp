#include <iostream>
#include <string>
#include <sstream>
#include <vector>

double SolveForX(std::string equation);
std::vector<std::string> StringToVector(std::string theString, char separator);

int main()
{
  std::cout << "Enter an equation to solve: ";
  std::string equation = "";
  getline(std::cin, equation);

  std::cout << "Solving for x for the equation " << equation << "\n";
  printf("x = %.2f\n", SolveForX(equation));

  return 0;
}

std::vector<std::string> StringToVector(std::string theString, char separator)
{
  std::vector<std::string> parts;
  std::stringstream ss(theString);
  std::string nextStr;

  while (getline(ss, nextStr, separator))
    parts.push_back(nextStr);

  return parts;
}

double SolveForX(std::string equation)
{
  std::vector<std::string> parts = StringToVector(equation, ' ');

  double x, y, c;
  std::string op, eq;

  if (parts.size() != 5)
  {
    throw "Equation must be of the form x [+,-,*,/] y = c, where y and c must be constants";
  }

  x = 0;
  op = parts[1];
  y = stod(parts[2]);
  eq = parts[3];
  c = stod(parts[4]);

  if (op == "+")
  {
    x = c - y;
  }
  else if (op == "-")
  {
    x = c + y;
  }
  else if (op == "*")
  {
    x = c / y;
  }
  else if (op == "/")
  {
    x = c * y;
  }

  return x;
}