#include "SortAlgos.h"
#include <iostream>

using namespace std;

class ListSortInt: public ListSort<int>
{
    public:
        ListSortInt( size_t count );  
};

ListSortInt::ListSortInt( size_t count ) : ListSort<int>(count)
{
    srand(time(nullptr));
    for (size_t ind = 0; ind < count; ind++)
    {
        push_back(rand());
    }
}

int main( void )
{
    ListSortInt l((size_t)200);
    cout << l.isSorted() << endl;

    cout << (l.gnomeSort()).isSorted() << endl;
    cout << (l.selectionSort()).isSorted() << endl;
    
    return 0; 
}
