#include <iostream>

int main() {

  try {
    std::cout << "Throwing exception" << std::endl;
    throw std::runtime_error("Just throw me around");
    std::cout << "Can you print me?\n";
  } catch (std::exception &ex) {
    std::cerr << "Handled Exception: " << ex.what() << std::endl;
  } catch (...) {
    std::cerr << "Default Exception (Catch all)";
  }

  return 0;
}