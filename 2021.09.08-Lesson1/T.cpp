#include <iostream>

using namespace std;

int main( void )
{
    int num, tens;
    
    cin >> num;

    tens = num % 100;
    cout << ((num / 100) == (tens / 10 + tens % 10 * 10)) << endl;

    return 0; 
}
