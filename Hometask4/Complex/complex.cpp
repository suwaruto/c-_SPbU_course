#include "complex.h"

Complex::~Complex() {}

Complex Complex::operator+( const Complex& z ) const
{
    return Complex(re + z.re, im + z.im);
}

Complex Complex::operator+( const float f ) const
{
    return Complex(re + f, im);
}

Complex operator+( const float f, const Complex& z )
{
    return Complex(f + z.re, z.im);
}

Complex Complex::operator-( const Complex& z ) const
{
    return Complex(re - z.re, im - z.im);
}

Complex Complex::operator-( const float f ) const
{
    return Complex(re - f, im);
}

Complex operator-( const float f, const Complex& z )
{
    return Complex(f - z.re, z.im);
}

Complex Complex::operator*( const Complex& z ) const
{
    return Complex(re * z.re - im * z.im, re * z.im + im * z.re);
}

Complex Complex::operator*( const float f ) const
{
    return Complex(re * f, im * f); 
}

Complex operator*( const float f, const Complex& z )
{
    return Complex(f * z.re, f * z.im);
}

float Complex::sqrmodulus() const
{
    return re * re + im * im;
}

Complex Complex::operator/( const Complex& z ) const
{
    return *this * z.adj() / z.sqrmodulus();
}

Complex Complex::operator/( const float f ) const
{
    return Complex(re / f, im / f);
}

Complex operator/( const float f, const Complex& z )
{
    return Complex(f * z.re / z.sqrmodulus(), -f * z.im / z.sqrmodulus());
}

Complex Complex::adj() const
{
    return Complex(re, -im);
}

bool Complex::operator==( const Complex& z ) const
{
    return (re == z.re) && (im == z.im);
}

bool Complex::operator==( const float f ) const
{
    return (re == f) && (im == 0);
}

bool operator==( const float f, const Complex& z)
{
    return (f == z.re) && (0 == z.im);
}

std::ostream& operator<<( std::ostream& stream, const Complex& z )
{
    if (z.re == 0)
    {
        if (z.im == 1)
            stream << "i";
        else if (z.im == -1)
            stream << "-i";
        else if (z.im == 0)
            stream << "0";
        else
            stream << z.im << "i";
        return stream;
    }
    stream << z.re;
    if (z.im > 0)
    {
        stream << " + ";
        if (z.im == 1)
            stream << "i";
        else
            stream << z.im << "i";
    }
    if (z.im < 0)
    {
        stream << " - ";
        if (z.im == -1)
            stream << "i";
        else
            stream << -z.im << "i";
    }
    return stream;
}
