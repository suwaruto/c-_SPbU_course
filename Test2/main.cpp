#include "ArrayList.h"
#include "LinkedList.h"

#include <iostream>
#include <fstream>

using namespace std;

LinkedList<int> listIn( int argc, char *argv[] )
{
    LinkedList<int> res;
    try
    {
        ifstream fin;
        fin.open(argv[1]);
        if (!fin)
        {
            throw "Failed opening file.";
        }
        while (!fin.eof())
        {
            int x;
            fin >> x;
            if (fin.eof()) break;
            res += x;
        }
        fin.close();
    }
    catch (const ios_base::failure& fail)
    {
        cerr << fail.what() << endl;
    }
    catch (const char * mes)
    {
        cerr << mes << endl;
    }
    return res;
}

void swap( int& a, int& b )
{
    int tmp = a;
    a = b;
    b = tmp;
}

void sort( ArrayList<int>& l, size_t first, size_t last )
{
    if (first >= last)
        return;
    int pivot = (l[first] + l[last]) >> 1;
    int i = first;
    int j = last;
    while (true)
    {
        while (pivot > l[i])
        {
            i++;
        }
        while (pivot < l[j])
        {
            j--;
        }
        if (i >= j)
        {
            break;
        }
        swap(l[i++], l[j--]);
    }
    sort(l, first, j);
    sort(l, j + 1, last);
}

void listOut( ArrayList<int>l, string path )
{
    ofstream fout;
    fout.open(path);
    fout << l << endl;
    fout.close();
}

int main( int argc, char *argv[] )
{
    ArrayList<int> al;
    LinkedList<int> ll = listIn(argc, argv);
    cout << ll << endl;

    al = ll;
    cout << al << endl;

    sort(al, 0, al.getLength() - 1);
    cout << al << endl;

    listOut(al, string(argv[2]) + "sorted.txt");

    return 0;
}
