#include "Stats.h"
#include <stdlib.h>     /* atoi */
#include <string>
using namespace std;
Stats::Stats()
{
    //ctor
	data.type = "";
	data.numberMean = 0.0;
        data.numberStandardDeviation = 0.0;
        data.speedMean = 0.0;
        data.speedStandardDeviation = 0.0;
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
    Types = new vehicleType[Number];
}

string Stats::getType() const
{
	return data.type;
}

int Stats::getNumberMean() const
{
	return data.numberMean;
}
int Stats::getNumberStandardDeviation() const
{
	return data.numberStandardDeviation;
}
int Stats::getSpeedMean() const
{
	return data.speedMean;
}
int Stats::getSpeedStandardDeviation() const
{
	return data.speedStandardDeviation;
}

void Stats::setType(string type)
{
	this->data.type = type;
}
void Stats::setNumberMean(float numberMean)
{
	this->data.numberMean = numberMean;
}
void Stats::setNumberStandardDeviation(float numberStandardDeviation)
{
	this->data.numberStandardDeviation = numberStandardDeviation;
}
void Stats::setSpeedMean(float speedMean)
{
	this->data.speedMean = speedMean;
}
void Stats::setSpeedStandardDeviation(float speedStandardDeviation)
{
	this->data.speedStandardDeviation = speedStandardDeviation;
}

ostream& operator << (ostream& out, Stats data)
{
        out << data.getType();
        out << ":";
        out << data.getNumberMean();
        out << ":";
        out << data.getNumberStandardDeviation();
        out << ":";
        out << data.getSpeedMean();
        out << ":";
        out << data.getSpeedStandardDeviation();
        return out;
}
istream& operator >> (istream& in, Stats &data)
{
	string type;
	string numberMean;
        string numberStandardDeviation;
        string speedMean;
        string speedStandardDeviation;
        
        getline(in, type,':');
        //cout << type;
        data.setType(type);
        cout << data.getType();
        getline(in, numberMean,':');
        data.setNumberMean(atoi (numberMean.c_str()));
        //cout << numberMean;
        getline(in, numberStandardDeviation,':');
        data.setNumberStandardDeviation(stoul (numberStandardDeviation, nullptr, 0));
        
        getline(in, speedMean,':');
        data.setSpeedMean(stoul (speedMean, nullptr, 0));
        
        getline(in, speedStandardDeviation,'\n');
        data.setSpeedStandardDeviation(stoul (speedStandardDeviation, nullptr, 0));
        return in;
}
