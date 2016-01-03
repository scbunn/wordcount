#include <iostream>
#include <fstream>

#include "WordCount.h"

int main(int argc, char *argv[]) {
  WordCount wc;

  if (argv[1]) {
    std::ifstream input(argv[1]);
    read(input, wc);
  } else {
    read(std::cin, wc);
  }
  print(std::cout, wc);
  return 0;
}
