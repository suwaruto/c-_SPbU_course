#include "ArrayList.h"

template <typename T>
class ListSort : public ArrayList<T>
{
    public:
        ListSort( std::size_t count ) : ArrayList<T>(count) {};
        ListSort gnomeSort();
        ListSort selectionSort();
        ListSort insertSort();
        bool isSorted();
};

using namespace std;

template <typename T>
void swp( T& var1, T& var2 )
{
    T tmp = var1;
    var1 = var2;
    var2 = tmp;
} 

template <typename T>
bool ListSort<T>::isSorted()
{
    size_t length = this->getLength();
    if (length <= 1)
    {
        return true;
    }
    for (size_t ind = 0; ind < length - 1; ind++)
    {
        if ((*this)[ind] > (*this)[ind + 1])
        {
            return false;
        }
    }
    return true;
}

template <typename T>
ListSort<T> ListSort<T>::gnomeSort()
{
    size_t pos = 0;
    size_t length = this->getLength();
    ListSort<T> l = *this;
    while (pos < length)
    {
        if (pos == 0 || l[pos] >= l[pos - 1])
        {
            pos++;
        }
        else
        {
            swp(l[pos], l[pos - 1]);
            pos--;
        }
    }
    return l;
}

template <typename T>
ListSort<T> ListSort<T>::selectionSort()
{
    ListSort<T> l = *this;
    size_t length = this->getLength();
    for (size_t sorted = 0; sorted < length; sorted++)
    {
        size_t min_ind = sorted;
        for (size_t ind = sorted; ind < length; ind++)
        {
            if (l[ind] < l[min_ind])
            {
                min_ind = ind;
            }
        }
        swp(l[sorted], l[min_ind]);
    }

    return l;
}

template <typename T>
ListSort<T> ListSort<T>::insertSort()
{
    ListSort<T> l = *this;    
    size_t length = this->getLength();
    for (size_t ind = 1; ind < length; ind++)
    {
        
}
