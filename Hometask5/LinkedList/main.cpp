#include <cstdlib>
#include <iostream>

#include "LinkedList.h"

int main( void )
{
    try
    {
        LinkedList<int> l;
        l.push_forward(4);
        l.push_forward(2);
        LinkedList<int> l1 = l;
        std::cout << l << std::endl;
        std::cout << l1 << std::endl;
        l1.insert(5, 1);
        std::cout << (l1 != l) << std::endl;
        std::cout << l1 << std::endl;
        l1.insert(1, 2);
        std::cout << l1 << std::endl;
        std::cout << l + l1 << std::endl;
        std::cout << l1.extract_ind(2) << std::endl;
        std::cout << l1 << std::endl;
        l1 += l;
        std::cout << l1 << std::endl;
        std::cout << l1.extract_ind(2) << std::endl;
        std::cout << l1 << std::endl;
    }
    catch (const char *exception)
    {
        std::cerr << exception << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
