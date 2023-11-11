#pragma once

// My includes
#include "myVector2.h"
#include "VoronoiDiagram.h"

class Arc;

class Event
{
public:
    enum class Type{SITE, CIRCLE};

    // Site event
    Event(VoronoiDiagram::Site* site);
    // Circle event
    Event(double y, myVector2 point, Arc* arc);

    const Type type;
    double y;
    int index;
    // Site event
    VoronoiDiagram::Site* site;
    // Circle event
    myVector2 point;
    Arc* arc;

};

bool operator<(const Event& lhs, const Event& rhs);
std::ostream& operator<<(std::ostream& os, const Event& event);

