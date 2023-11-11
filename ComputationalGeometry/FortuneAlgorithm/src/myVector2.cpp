#include "myVector2.h"
// STL
#include <cmath>

myVector2::myVector2(double x, double y) : x(x), y(y){}

// Unary operators
myVector2 myVector2::operator-() const
{
    return myVector2(-x, -y);
}

myVector2& myVector2::operator+=(const myVector2& other)
{
    x += other.x;
    y += other.y;
    return *this;
}

myVector2& myVector2::operator-=(const myVector2& other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

myVector2& myVector2::operator*=(double t)  
{
    x *= t;
    y *= t;
    return *this; 
}

// Other operations

myVector2 myVector2::getOrthogonal() const
{
    return myVector2(-y, x);
}

double myVector2::dot(const myVector2& other) const
{
    return x * other.x + y * other.y;
}

double myVector2::getNorm() const
{
    return std::sqrt(x * x + y * y);
}

double myVector2::getDistance(const myVector2& other) const
{
    return (*this - other).getNorm();
}

double myVector2::getDet(const myVector2& other) const
{
    return x * other.y - y * other.x;
}

myVector2 operator+(myVector2 lhs, const myVector2& rhs)
{
    lhs += rhs;
    return lhs;
}

myVector2 operator-(myVector2 lhs, const myVector2& rhs) 
{
    lhs -= rhs;
    return lhs;
}

myVector2 operator*(double t, myVector2 vec)
{
    vec *= t;
    return vec;
}

myVector2 operator*(myVector2 vec, double t)
{
    return t * vec;
}

std::ostream& operator<<(std::ostream& os, const myVector2& vec)
{
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}

void myVector2::scaler(const myVector2 & windowFactor, const double & t){
    x = x * windowFactor.x + t;
    y = y * windowFactor.y + t;
}
