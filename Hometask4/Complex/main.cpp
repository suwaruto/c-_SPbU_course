#include <iostream>

#include "complex.h"

using namespace std;

void evalIntRoots(Complex roots[3])
{
    Complex a(1, 0);
    Complex b(-2, -5);
    Complex c(-17, 4);
    Complex d(34, -63);

    Complex z;
    int k = 0;
    for (int re = -10; re < 10; re++)
        for (int im = -10; im < 10; im++)
        {
            z.re = re;
            z.im = im;
            if (a * z * z * z + b * z * z + c * z + d == 0)
            {
                roots[k++] = z;
                if (k >= 3)
                    break;
            }
        }
}

int main( int argc, char **argv )
{
    Complex z1(1, 0);
    Complex z2(3, 4);
    Complex z3(0, 1);
    Complex z4(0, -1);

    cout << z1 << endl << z2 << endl << z2.adj() << endl << z3 << endl;
    cout << z4 << endl;

    cout << z2 + z2.adj() << endl;
    cout << z2 - z2.adj() << endl;
    cout << z2 * z2 << endl;
    cout << z2 * 4 << endl;
    cout << 11 * z4 << endl;
    cout << z2 / 2 << endl;
    cout << 2 / z4 << endl;
    cout << z3 / z4 << endl;

    Complex roots[3];
    evalIntRoots(roots);

    cout << "The roots are: " << roots[0] << "; " 
        << roots[1] << "; " << roots[2] << endl;

    return EXIT_SUCCESS; 
}

