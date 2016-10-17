#include "Stats.h"
#include <string>
using namespace std;
Stats::Stats()
{
    //ctor
	type = "";
	numberMean = 0.0;
        numberStandardDeviation = 0.0;
        speedMean = 0.0;
        speedStandardDeviation = 0.0;
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
	return type;
}

float Stats::getNumberMean() const
{
	return numberMean;
}
float Stats::getNumberStandardDeviation() const
{
	return numberStandardDeviation;
}
float Stats::getSpeedMean() const
{
	return speedMean;
}
float Stats::getSpeedStandardDeviation() const
{
	return speedStandardDeviation;
}

void Stats::setType(string type)
{
	this->type = type;
}
void Stats::setNumberMean(float numberMean)
{
	this->numberMean = numberMean;
}
void Stats::setNumberStandardDeviation(float numberStandardDeviation)
{
	this->numberStandardDeviation = numberStandardDeviation;
}
void Stats::setSpeedMean(float speedMean)
{
	this->speedMean = speedMean;
}
void Stats::setSpeedStandardDeviation(float speedStandardDeviation)
{
	this->speedStandardDeviation = speedStandardDeviation;
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
        cout << type;
        data.setType(type);
        
        getline(in, numberMean,':');
        data.setNumberMean(stof (numberMean, nullptr));
        cout << numberMean;
        getline(in, numberStandardDeviation,':');
        data.setNumberStandardDeviation(stof (numberStandardDeviation, nullptr));
        
        getline(in, speedMean,':');
        data.setSpeedMean(stof (speedMean, nullptr));
        
        getline(in, speedStandardDeviation,'\n');
        data.setSpeedStandardDeviation(stof (speedStandardDeviation, nullptr));

        return in;
}
