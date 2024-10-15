#include <iostream>

int main(void)
{
  int a = 8, b = 11;
  while (a>0 || b>0) {
    std::cout << a-- << " " << b-- << std::endl;
  }

  return 0;
}

