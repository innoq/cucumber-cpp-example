#include "Calculator.h"
#include <iostream>

int main() {
  Calculator calc;
  calc.push(2);
  calc.push(3);
  auto result = calc.add();

  std::cout << "result:" << result << std::endl;

  return 0;
}
