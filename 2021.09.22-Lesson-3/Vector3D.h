#ifndef VECTOR3D
#define VECTOR3D

struct Vector3D
{
    Vector3D();
    Vector3D( double x, double y, double z );
    Vector3D( const Vector3D& v );
    ~Vector3D();
    
    double x;
    double y;
    double z;

    Vector3D Add( Vector3D v );
    Vector3D Scalar_Multiply( double scalar );
    double Dot_Product( Vector3D v );
    Vector3D Cross_Product( Vector3D v ); // == (this) x v

    void Print();
};

#endif
