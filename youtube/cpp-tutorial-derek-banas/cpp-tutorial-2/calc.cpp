#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

int main() {
 
  std::string sInput;

  std::cout << "Enter calculation (eg. 5 + 10): ";
  getline(std::cin, sInput);


  std::stringstream ss(sInput);
  std::vector<std::string> vecsOps;
  std::string sNextOp;
  char cSpace = ' ';

  while(getline(ss, sNextOp, cSpace)) {
    vecsOps.push_back(sNextOp);
  }

  double dbOp1 = std::stod(vecsOps[0]);
  std::string sOp = vecsOps[1];
  double dbOp2 = std::stod(vecsOps[2]);

  if (sOp == "+") {
    printf("%.1f %s %.1f = %.1f\n", dbOp1, sOp.c_str(), dbOp2, (dbOp1 + dbOp2));
  } else if (sOp == "-") {
    printf("%.1f %s %.1f = %.1f\n", dbOp1, sOp.c_str(), dbOp2, (dbOp1 - dbOp2));
  } else if (sOp == "*") {
    printf("%.1f %s %.1f = %.1f\n", dbOp1, sOp.c_str(), dbOp2, (dbOp1 * dbOp2));
  } else if (sOp == "/") {
    printf("%.1f %s %.1f = %.1f\n", dbOp1, sOp.c_str(), dbOp2, (dbOp1 / dbOp2));
  } else {
    std::cout << sOp << " operator not supported. Please only enter +, -, *, /" << std::endl;
  }

  return 0;
}