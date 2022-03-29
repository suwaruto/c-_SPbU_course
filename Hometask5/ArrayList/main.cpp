#include <iostream>
#include "ArrayList.h"

using namespace std;

int main( void )
{
    ArrayList<int> l1;
    ArrayList<int> l2;

    l1 += 5;
    4 += l1;
    l1 += l2;
    l1 += 11;
    cout << l1 << endl;

    l1.insert(3, 30);
    cout << l1 << endl;
    l1.insert(3, 50);
    cout << l1 << endl;

    l1 += 1000;
    cout << l1 << endl;
    l1.extract_index(2);
    cout << l1 << endl;

    l1.extract_value(30);
    cout << l1 << endl;
    
    return EXIT_SUCCESS;
}
