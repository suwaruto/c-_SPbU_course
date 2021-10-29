#include <ostream>

struct Complex
{
    float re;
    float im;

    Complex() : re(0), im(0) {};
    Complex( float re, float im = 0) : re(re), im(im) {};
    Complex( const Complex &z ) : re(z.re), im(z.im) {};

    ~Complex();

    Complex adj() const;
    float sqrmodulus() const; 

    Complex operator+( const Complex& ) const;
    Complex operator+( const float ) const;
    friend Complex operator+( const float, const Complex& );

    Complex operator-( const Complex& ) const;
    Complex operator-( const float ) const;
    friend Complex operator-( const float, const Complex& );

    Complex operator*( const Complex& ) const;
    Complex operator*( const float ) const;
    friend Complex operator*( const float, const Complex& );

    Complex operator/( const Complex& ) const;
    Complex operator/( const float ) const;
    friend Complex operator/( const float, const Complex& );

    bool operator==( const Complex& ) const;
    bool operator==( const float ) const;
    friend bool operator==( const float, const Complex& );

    friend std::ostream& operator<<( std::ostream&, const Complex& );
};
