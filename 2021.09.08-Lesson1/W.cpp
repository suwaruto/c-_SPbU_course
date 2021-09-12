#include <iostream>

using namespace std;

int main( void )
{
    int a, b, c;

    cin >> a >> b >> c;

    if (a > b)
        a ^= b ^= a ^= b; 
    if (b > c)
        b ^= c ^= b ^= c;
    if (a > b)
        a ^= b ^= a ^= b; 

    if (a + b <= c)
        cout << "Impossible" << endl;
    else if (a * a + b * b > c * c)
        cout << "Acute" << endl;
    else if (a * a + b * b == c * c)
        cout << "Right" << endl;
    else
        cout << "Obtuse" << endl;

    return 0;
}
