#include <cstdio>
#include <iostream>

using namespace std;

int main( void )
{
    int sec;
    int ss, mm, h;

    cin >> sec;

    ss = sec % 60;
    mm = sec / 60 % 60;
    h = sec / 3600; 

    printf("%d:%02d:%02d\n", h, mm, ss);

    return 0;
}
