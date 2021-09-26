#include <iostream>

#include "Vector3D.h"

using namespace std;

int main( void )
{
    Vector3D v1(1, 2, 3);
    Vector3D v2(4, 5, 6);
    double scalar = 5;

    Vector3D sum = v1.Add(v2);
    Vector3D scprod = v1.Scalar_Multiply(scalar);
    double dotprod = v1.Dot_Product(v2);
    Vector3D xprod = v1.Cross_Product(v2);

    sum.Print();
    scprod.Print();
    cout << dotprod << endl;
    xprod.Print();

    return EXIT_SUCCESS;
}
