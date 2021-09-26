#include <iostream>

#include "Vector3D.h"

Vector3D::Vector3D()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3D::Vector3D( double x, double y = 0, double z = 0 )
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3D::Vector3D( const Vector3D& v )
{
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}

Vector3D::~Vector3D()
{
    
}

Vector3D Vector3D::Add( Vector3D v )
{
    Vector3D result;

    result.x = x + v.y;
    result.y = y + v.y;
    result.z = z + v.z;

    return result;
}

Vector3D Vector3D::Scalar_Multiply( double scalar )
{
    Vector3D result;

    result.x = x * scalar;
    result.y = y * scalar;
    result.z = z * scalar;

    return result;
}

double Vector3D::Dot_Product( Vector3D v )
{
    return v.x * x + v.y * y + v.z * z;
}

Vector3D Vector3D::Cross_Product( Vector3D v ) // result == (this) x v
{
    Vector3D result;

    result.x = y * v.z - z * v.y;
    result.y = -x * v.z + z * v.x;
    result.z = x * v.y - y * v.x;

    return result;
}

void Vector3D::Print()
{
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}
