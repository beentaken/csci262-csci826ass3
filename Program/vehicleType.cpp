/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 14/10/2016
-------------------------------------------------------------*/
#include <iostream>
#include <string>
#include "vehicleType.h"
using namespace std;
vehicleType::vehicleType()	// Constructor
{
	parkable = false;
	regisration = "";
	weightVolume = 0;
	weightSpeed = 0;
	
	turnProbability = 0.1;
	parkProbability = 0.1;
	speedUpProbability = 0.05;
	speedDownProbability = 0.05;
	continuingDrivingProbability = 0.70;
	
	stilParkProbability = 0.5;
	resumingJourneyProbability = 0.5;
}
vehicleType::~vehicleType()	// destructor
{
	parkable = false;
	regisration = "";
	weightVolume = 0;
	weightSpeed = 0;
	
	turnProbability = 0.1;
	parkProbability = 0.1;
	speedUpProbability = 0.05;
	speedDownProbability = 0.05;
	continuingDrivingProbability = 0.70;
	
	stilParkProbability = 0.5;
	resumingJourneyProbability = 0.5;
}
bool vehicleType::getParkable() const
{
	return parkable;
}
string vehicleType::getRegisration() const
{
	return regisration;
}
int vehicleType::getWeightVolume() const
{
	return weightVolume;
}
int vehicleType::getWeightSpeed() const
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
float vehicleType::getSpeedUpProbability() const
{
	return speedUpProbability;
}
float vehicleType::getSpeedDownProbability() const
{
	return speedDownProbability;
}
float vehicleType::getContinuingDrivingProbability() const
{
	return continuingDrivingProbability;
}
		
float vehicleType::getStilParkProbability() const
{
	return stilParkProbability;
}
float vehicleType::getResumingJourneyProbability() const
{
	return resumingJourneyProbability;
}	
void vehicleType::setParkable(bool parkable)
{
	this->parkable = parkable;
	return;
}
void vehicleType::setRegisration(string regisration)
{
	this->regisration = regisration;
	return;
}
void vehicleType::setWeightVolume(unsigned int weightVolume)
{
	this->weightVolume = weightVolume;
	return;
}
void vehicleType::setWeightSpeed(unsigned int weightSpeed)
{
	this->weightSpeed = weightSpeed;
	return;
}

void vehicleType::setTurnProbability(float turnProbability)
{
	this->turnProbability = turnProbability;
	return;
}
void vehicleType::setParkProbability(float parkProbability)
{
	this->parkProbability = parkProbability;
	return;
}
void vehicleType::setSpeedUpProbability(float speedUpProbability)
{
	this->speedUpProbability = speedUpProbability;
	return;
}
void vehicleType::setSpeedDownProbability(float speedDownProbability)
{
	this->speedDownProbability = speedDownProbability;
	return;
}
void vehicleType::setContinuingDrivingProbability(float continuingDrivingProbability)
{
	this->continuingDrivingProbability = continuingDrivingProbability;
	return;
}
		
void vehicleType::setStilParkProbability(float stilParkProbability)
{
	this->stilParkProbability = stilParkProbability;
	return;
}
void vehicleType::setResumingJourneyProbability(float resumingJourneyProbability)
{
	this->resumingJourneyProbability = resumingJourneyProbability;
	return;
}
ostream& operator << (ostream& out, vehicleType data)
{
        out << data.getParkable();
        out << ":";
        out << data.getRegisration();
        out << ":";
        out << data.getWeightVolume();
        out << ":";
        out << data.getWeightSpeed();
        return out;
}
istream& operator >> (istream& in, vehicleType &data)
{
        string name;
	string parkable;
	string regisration;
	string weightVolume;
	string weightSpeed;
        
        getline(in, parkable,':');
        if (parkable == "0")
        	data.setParkable(false);
        else if (parkable == "1")
        	data.setParkable(true);
        
        getline(in, regisration,':');
        data.setRegisration(regisration);
        
        getline(in, weightVolume,':');
        data.setWeightVolume(stoul (weightVolume, nullptr, 0));
        
        getline(in, weightSpeed,'\n');
        data.setWeightSpeed(stoul (weightSpeed, nullptr, 0));

	
        return in;
}
