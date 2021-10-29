#include <iostream>
#include <cstdlib>
#include <ctime>

const int LENGTH = 100;

using namespace std;

void swap( int& val1, int& val2 )
{
    int tmp = val1;
    val1 = val2;
    val2 = tmp;
}

void shuffle( int *arr )
{
    srand(time(0));
    for (int k = LENGTH - 1; k >= 0; k--)
        swap(arr[k], arr[rand() % 100]);
}

void randNegatify( int *arr )
{
    for (int k = 0; k < LENGTH; k++)
        arr[k] = rand() % 2? arr[k] : -arr[k];
}

int sum( int *arr )
{
    int res = 0;
    for (int k = 0; k < LENGTH; k++)
        res += arr[k];

    return res;
}

int negProduct( int *arr )
{
    int res = 1;
    for (int k = 0; k < LENGTH; k++)
        if (arr[k] < 0)
            res *= arr[k];

    return res;
}

int countEven( int *arr )
{
    int count = 0;
    for (int k = 0; k < LENGTH; k++)
        if ((arr[k] & 1) == 0)
            count++;
    
    return count;
}

int main( void )
{
    int arr[LENGTH] = { 0 }; 
    for (int k = 0; k < LENGTH; k++)
        arr[k] = k;
    shuffle(arr);
    randNegatify(arr);
    for (int k = 0; k < LENGTH; k++)
        cout << arr[k] << " ";
    cout << endl;
    cout << sum(arr) << endl << negProduct(arr) << endl << countEven(arr) << 
        endl;

    return EXIT_SUCCESS;
}
