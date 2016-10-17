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

void Stats::InitializeData(int num)
{
    this->StatData = new Data[num];
}

void Stats::SetData(Data Node, int position)
{
    this->StatData[position] = Node;
}
