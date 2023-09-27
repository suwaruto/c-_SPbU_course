#include "bst.h"

int main( void )
{
  Set<int> s;
  s.addElement(4);
  s.addElement(5);
  s.addElement(3);
  s.addElement(-1);
  s.addElement(10);
  std::cout << s << std::endl;

  Set<int> s1;
  s1.addElement(4);
  s1.addElement(22);
  s1.addElement(-2);
  s1.addElement(5);
  std::cout << s1 << std::endl;

  Set<int> s2 = s;

  std::cout << s2 << std::endl;

  std::cout << GetIntersection(s2, s1) << std::endl;
  std::cout << GetUnion(s2, s1) << std::endl;
  std::cout << GetDifference(s2, s1) << std::endl;

  return 0;
}
