#include <iostream>
#include <ctime>
#include <cstring> //memmove

const int INITIAL_ARR_LENGTH = 180;
const int LENGTH = 100;

using namespace std;

void swap( int& val1, int& val2 )
{
    int tmp = val1;
    val1 = val2;
    val2 = tmp;
}

void shuffle( int *arr, int length )
{
    srand(time(0));
    for (int k = length - 1; k >= 0; k--)
        swap(arr[k], arr[rand() % 100]);
}

int sum( int *arr, int length )
{
    int res = 0;
    for (int k = 0; k < length; k++)
        res += arr[k];

    return res;
}

long long int negProduct( int *arr, int length )
{
    int res = 1;
    for (int k = 0; k < length; k++)
        if (arr[k] < 0)
            res *= arr[k];

    return res;
}

int countEven( int *arr, int length )
{
    int count = 0;
    for (int k = 0; k < length; k++)
        if ((arr[k] & 1) == 0)
            count++;
    
    return count;
}

int minimum( int *arr, int length, int& index_min )
{
    int min = 100;
    index_min = -1;
    for (int k = 0; k < length; k++)
        if (arr[k] < min)
        {
            min = arr[k];
            index_min = k;
        }

    return min;
}

int maximum( int *arr, int length, int& index_max )
{
    int max = -100;
    index_max = -1;
    for (int k = 0; k < length; k++)
        if (arr[k] > max)
        {
            max = arr[k];
            index_max = k;
        }
    return max;
}

int secondMinimum( int *arr, int length, int& index_second_min )
{
    int index_min = -1;
    int min = minimum(arr, length, index_min);
    int second_min = 100;
    index_second_min = -1;

    for (int k = 0; k < length; k++)
        if (k != index_min)
            if (arr[k] < second_min)
            {  
                second_min = arr[k];
                index_second_min = k;
            }

    return second_min;
}

void swapInPairs( int *arr, int length )
{
    if (length != 1)
        for (int k = 0; k < length; k += 2)
            swap(arr[k], arr[k + 1]);
}

void reverseArray( int *arr, int length ) //1 2 3 4 -> 4 3 2 1; 1 2 3 -> 3 2 1
{
    for (int k = 0; k < length / 2; k++)
        swap(arr[k], arr[length - k - 1]);
}

void deleteBetweenMaxMin( int *arr, int& length )
{
    int index_min = -1;
    int index_max = -1;

    minimum(arr, length, index_min);
    maximum(arr, length, index_max);
     
    int start = index_min < index_max ? index_min : index_max;
    int end = index_max > index_min ? index_max : index_min;

    if (start + 1 <= end - 1)
    {
        memmove(arr + start + 1, arr + end, 
            sizeof(arr[0]) * (length - end + start));
        length = length - end + start + 1;
    }
}

void insertZero( int *arr, int& length )
{
    if (length == 1) return;
    memmove(arr + length / 2 + 1, arr + length / 2, sizeof(arr[0]) * (length / 2));
    arr[length / 2] = 0;
    length++;
}

void outputArray( int *arr, int length )
{
    for (int k = 0; k < length; k++)
        cout << arr[k] << " ";
    cout << endl;
}

int main( void )
{
    int arr[INITIAL_ARR_LENGTH] = { 0 }; 
    for (int k = 10; k < 100; k++)
        arr[k - 10] = k;
    for (int k = 100; k < INITIAL_ARR_LENGTH + 10; k++)
        arr[k - 10] = 90 - k;
    shuffle(arr, INITIAL_ARR_LENGTH);

    int length = 100;
    cout << "Enter length of an array (<= 100): ";
    cin >> length;
    outputArray(arr, length);

    cout << "Sum == " << sum(arr, length) << endl;
    cout << "negProduct == " << negProduct(arr, length) << endl;
    cout << "countEven == " << countEven(arr, length) << endl;

    int index_second_min = -1;
    int second_minimum = 100;
    second_minimum = secondMinimum(arr, length, index_second_min);
    cout << "Second minimum == arr[" << index_second_min << "] == " << second_minimum << endl;

    swapInPairs(arr, length);
    cout << "After swapping in pairs: " << endl;
    outputArray(arr, length);

    reverseArray(arr, length);
    cout << "After reversing: " << endl;
    outputArray(arr, length);

    deleteBetweenMaxMin(arr, length);
    cout << "After deleting all elements between minimum and maximum: " << endl;
    outputArray(arr, length);

    insertZero(arr, length);
    cout << "After inserting zero: " << endl;
    outputArray(arr, length);

    return EXIT_SUCCESS;
}
