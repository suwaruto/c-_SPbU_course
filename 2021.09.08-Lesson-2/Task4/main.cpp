#include <iostream>

using namespace std;

void parentheses( string source )
{
    int result_length = 2 * source.length() + (source.length() % 1);

    if (source.length() & 1)
    {
        for (int i = 0; i < source.length() / 2; i++)
            cout << source[i] << " (";
        for (int i = source.length() / 2; i < source.length() - 1; i++)
            cout << source[i] << ") ";

        cout << source[source.length() - 1] << endl;
    }
    else
    {
        for (int i = 0; i < source.length() / 2 - 1; i++)
            cout << source[i] << " (";
        cout << source[source.length() / 2 - 1];
        for (int i = source.length() / 2; i < source.length() - 1; i++)
            cout << source[i] << ") ";

        cout << source[source.length() - 1] << endl;
    }
}

int main( void )
{
    string s;

    cin >> s;

    parentheses(s);

    return 0;
}
