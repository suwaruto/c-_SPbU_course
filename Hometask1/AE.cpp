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

    cout << a << ' ' << b << ' ' << c << endl;

    return 0;
}
