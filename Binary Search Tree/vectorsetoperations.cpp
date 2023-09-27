#include "vectorsetoperations.h"

#include <iostream>

int main( void )
{
  std::vector<int> v1{1, 2, 3, 5, 10, 22, 37, 41};
  std::vector<int> v2{1, 3, 7, 9, 21, 37, 42};

  std::vector<int> v = substract(v1, v2);

  for (int n : v) 
    std::cout << n << ' ';

  std::cout << std::endl;

  return 0;
}

