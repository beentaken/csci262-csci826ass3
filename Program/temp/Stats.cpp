#include "Stats.h"

Stats::Stats()
{
    //ctor
}

Stats::~Stats()
{
    //dtor
}

Stats::Stats(const Stats& other)
{
    //copy ctor
}

Stats& Stats::operator=(const Stats& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Stats::InitializeTypes(int Number)
{
    Types = new VehicleType[Number];
}
