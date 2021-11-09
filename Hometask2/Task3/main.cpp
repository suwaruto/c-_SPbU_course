#include <iostream>

using namespace std;

void hanoi( int n, int source, int target, int aux )
{
    if (n == 1)
        cout << "Move disk 1 from " << source << " to " << target << endl;
    else
    {
        hanoi(n - 1, source, aux, target);
        cout << "Move disk " << n << " from " << source << " to " << target <<
            endl;
        hanoi(n - 1, aux, target, source);
    }
     
}

int main( void )
{
    int n; 

    cin >> n;

    hanoi(n, 1, 2, 3);

    return 0;
}


