#include <iostream>

int main() {
  [[maybe_unused]] double pi{3.1415926};
  [[maybe_unused]] double gravity{9.8};
  [[maybe_unused]] double phi{1.61803};

  std::cout << pi << '\n';
  std::cout << phi << '\n';

  return 0;
}
