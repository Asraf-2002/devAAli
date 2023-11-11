#pragma once

// STL
#include <ostream>

// Declarations

class myVector2;
myVector2 operator-(myVector2 lhs, const myVector2& rhs);

// Implementations

class myVector2{
public:
    double x;
    double y;
    myVector2(double x = 0.0, double y = 0.0);
    
    // Unary operators
    myVector2 operator-() const;
    myVector2& operator+=(const myVector2& other);
    myVector2& operator-=(const myVector2& other);
    myVector2& operator*=(double t);
    
    // Other operations
    myVector2 getOrthogonal() const;
    double dot(const myVector2& other) const;
    double getNorm() const;
    double getDistance(const myVector2& other) const;
    double getDet(const myVector2& other) const;

    //To scale points inside the window...
    void scaler(const myVector2 &, const double &);
};

// Binary operators
myVector2 operator+(myVector2 lhs, const myVector2& rhs);
myVector2 operator-(myVector2 lhs, const myVector2& rhs);
myVector2 operator*(double t, myVector2 vec);
myVector2 operator*(myVector2 vec, double t);
std::ostream& operator<<(std::ostream& os, const myVector2& vec);

