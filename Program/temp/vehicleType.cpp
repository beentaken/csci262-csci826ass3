/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 14/10/2016
-------------------------------------------------------------*/
#include <iostream>
#include "vehicleType.h"
using namespace std;
vehicleType::vehicleType()	// Constructor
{
	name = "";
	parkable = false;
	regisrationFormat = "";
	weightVolume = 0;
	weightSpeed = 0;
	turnProbability = 0.0;
	parkProbability = 0.0;
	speedChangeProbability = 0.0;
	lawBreakerProbability = 0.0;
}
vehicleType::~vehicleType()	// destructor
{
	name = "";
	parkable = false;
	regisrationFormat = "";
	weightVolume = 0;
	weightSpeed = 0;
	turnProbability = 0.0;
	parkProbability = 0.0;
	speedChangeProbability = 0.0;
	lawBreakerProbability = 0.0;
}
string vehicleType::getName() const
{
	return name;
}
bool vehicleType::getParkable() const
{
	return parkable;
}
string vehicleType::getRegisrationFormat() const
{
	return regisrationFormat;
}
unsigned int vehicleType::getWeightVolume() const
{
	return weightVolume;
}
unsigned int vehicleType::getWeightSpeed() const
{
	return weightSpeed;
}
float vehicleType::getTurnProbability() const
{
	return turnProbability;
}
float vehicleType::getParkProbability() const
{
	return parkProbability;
}
float vehicleType::getSpeedChangeProbability() const
{
	return speedChangeProbability;
}
float vehicleType::getLawBreakerProbability() const
{
	return lawBreakerProbability;
}

void vehicleType::setName(string name)
{
	this->name = name;
}
void vehicleType::setParkable(bool parkable)
{
	this->parkable = parkable;
}
void vehicleType::setRegisrationFormat(string regisrationFormat)
{
	this->regisrationFormat = regisrationFormat;
}
void vehicleType::setWeightVolume(unsigned int weightVolume)
{
	this->weightVolume = weightVolume;
}
void vehicleType::setWeightSpeed(unsigned int weightSpeed)
{
	this->weightSpeed = weightSpeed;
}
void vehicleType::setTurnProbability(float turnProbability)
{
	this->turnProbability = turnProbability;
}
void vehicleType::setParkProbability(float parkProbability)
{
	this->parkProbability = parkProbability;
}
void vehicleType::setSpeedChangeProbability(float speedChangeProbability)
{
	this->speedChangeProbability = speedChangeProbability;
}
void vehicleType::setLawBreakerProbability(float lawBreakerProbability)
{
	this->lawBreakerProbability = lawBreakerProbability;
}
ostream& operator << (ostream& out, vehicleType data)
{
        out << data.getName();
        out << ":";
        out << data.getParkable();
        out << ":";
        out << data.getRegisrationFormat();
        out << ":";
        out << data.getWeightVolume();
        out << ":";
        out << data.getWeightSpeed();
        return out;
}
/*
CANT GETLINE A BOOLEAN
istream& operator >> (istream& in, vehicleType &data)
{
        string name;
	bool parkable;
	string regisrationFormat;
	unsigned int weightVolume;
	unsigned int weightSpeed;

        getline(in, name,':');
        data.setName(name);

        getline(in, parkable,':');
        if (atof(parkable.c_str()) == 0)
        	data.setParkable(false);
        else if (atof(parkable.c_str()) == 1)
        	data.setParkable(true);

        getline(in, regisrationFormat,':');
        data.setRegisrationFormat(regisrationFormat);

        getline(in, weightVolume,':');
        data.setWeightVolume(weightVolume);

        getline(in, weightSpeed,'\n');
        data.setWeightSpeed(weightSpeed);
        return in;
}
*/
