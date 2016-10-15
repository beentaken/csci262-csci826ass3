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
float vehicleType::getSpeedChangeProbability() const
{
	return speedChangeProbability;
}
float vehicleType::getLawBreakerProbability() const
{
	return lawBreakerProbability;
}
	
void vehicleType::getName(string name)
{
	this.name = name;
	return;
}
void vehicleType::getParkable(bool parkable)
{
	this.parkable = parkable;
	return;
}
void vehicleType::getRegisrationFormat(string regisrationFormat)
{
	this.regisrationFormat = regisrationFormat;
	return;
}
void vehicleType::getWeightVolume(int weightVolume)
{
	this.weightVolume = weightVolume;
	return;
}
void vehicleType::getWeightSpeed(int weightSpeed)
{
	this.weightSpeed = weightSpeed;
	return;
}
void vehicleType::getTurnProbability(float turnProbability)
{
	this.turnProbability = turnProbability;
	return;
}
void vehicleType::getParkProbability(float parkProbability)
{
	this.parkProbability = parkProbability;
	return;
}
void vehicleType::getSpeedChangeProbability(float speedChangeProbability)
{
	this.speedChangeProbability = speedChangeProbability;
	return;
}
void vehicleType::getLawBreakerProbability(float lawBreakerProbability)
{
	this.lawBreakerProbability = lawBreakerProbability;
	return;
}
