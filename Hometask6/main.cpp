#include "CursorList.h"

#include <iostream>

int main( void )
{
    CursorList<int> l;
    l += 4;
    l += 3;
    l.push_forward(1);
    l.push_forward(10);
    l.push_back(12);
    CursorList<int> l2 = l;
    std::cout << l << std::endl;
    std::cout << l2 << std::endl;
    l2.push_forward(11);
    std::cout << l2 << std::endl;
    std::cout << l2[10] << std::endl;
    l.insert(35, 2);
    std::cout << l << std::endl;
    std::cout << (l += l2) << std::endl;
    std::cout << l.extract_head() << std::endl;
    std::cout << l << std::endl;
    std::cout << l.extract_tail() << std::endl;
    std::cout << l << std::endl;
    return EXIT_SUCCESS; 
}
