#include <iostream>

using namespace std;

unsigned int C( unsigned int n, unsigned int k )
{
    if (n < k)
        return 0;
    else if (n == k)
        return 1;
    else if (k == 0)
        return 1;
    else
        return C(n - 1, k) + C(n - 1, k - 1);
}

int main( void )
{
    int n;
    int k;

    cin >> n >> k;
    cout << C(n, k) << endl;
    
    return 0; 
}
