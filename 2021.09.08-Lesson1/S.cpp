#include <iostream>

using namespace std;

int main( void )
{
    int h, a, b;

    cin >> h >> a >> b;

    cout << (h - b - 1) / (a - b) + 1 << endl;

    return 0; 
}

