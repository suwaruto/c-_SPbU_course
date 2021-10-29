#include <iostream>

using namespace std;

void parentheses( string source )
{
    int result_length = 2 * source.length() + (source.length() % 1);

    cout << "(";

    if (source.length() & 1)
    {
        for (int i = 0; i < source.length() / 2; i++)
            cout << source[i] << " (";
        for (int i = source.length() / 2; i < source.length() - 1; i++)
            cout << source[i] << ") ";
    }
    else
    {
        for (int i = 0; i < source.length() / 2 - 1; i++)
            cout << source[i] << " (";
        cout << source[source.length() / 2 - 1];
        for (int i = source.length() / 2; i < source.length() - 1; i++)
            cout << source[i] << ") ";
    }
    cout << source[source.length() - 1] << ")" <<  endl;
}

void parentheses_rec( string& source, int ind )
{
    if (ind < (source.length() >> 1)) 
    {
        cout << "(" << source[ind] << " ";
        parentheses_rec(source, ind + 1);
        cout << source[source.length() - 1 - ind] << ") ";
    }
    else
        if (source.length() & 1)
            cout << "(" << source[ind] << ") ";
        else
            ;
}

int main( void )
{
    string s;

    cin >> s;

    parentheses_rec(s, 0);
    cout << endl;

    parentheses(s);

    return 0;
}
