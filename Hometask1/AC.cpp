#include <iostream>

using namespace std;

int main( void )
{
    int a, b, c;

    cin >> a >> b >> c;

    if (a & 1)
        if (!(b & 1))
            cout << "YES" << endl;
        else if (!(c & 1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    else
        if (b & 1)
            cout << "YES" << endl;
        else if (c & 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    return 0;
}
