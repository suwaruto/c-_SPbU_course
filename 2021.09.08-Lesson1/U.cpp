#include <iostream>

using namespace std;

int main( void )
{
    int m, n;

    cin >> m >> n;

    cout << !((m % n) && (n % m)) << endl;

    return 0; 
}

