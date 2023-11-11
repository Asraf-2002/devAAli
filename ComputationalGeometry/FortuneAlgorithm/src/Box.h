#pragma once

// STL
#include <array>
#include <limits>
// My includes
#include "myVector2.h"

class Box{
public:
    // Be careful, y-axis is oriented to the top like in math
    enum class Side : int {LEFT, BOTTOM, RIGHT, TOP};

    struct Intersection
    {
        Side side;
        myVector2 point;
    };

    double left;
    double bottom;
    double right;
    double top;

    bool contains(const myVector2& point) const;
    Intersection getFirstIntersection(const myVector2& origin, const myVector2& direction) const; // Useful for Fortune's algorithm
    int getIntersections(const myVector2& origin, const myVector2& destination, std::array<Intersection, 2>& intersections) const; // Useful for diagram intersection

private:
    static constexpr double EPSILON = std::numeric_limits<double>::epsilon();
};

