#include <iostream>

using namespace std;

void symcut( string src )
{
    for (int i = 0; i < src.length() / 2; i++)
        if (src[i] == src[src.length() - 1 - i])
            src[i] = src[src.length() - 1 - i] = '*';
    for (int i = 0; i < src.length(); i++)
        if (src[i] != '*')
            cout << src[i];
    cout << endl;
}

int main( void )
{
    string str;

    cin >> str;

    symcut(str);

    return 0;
}
