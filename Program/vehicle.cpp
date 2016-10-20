/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 14/10/2016
-------------------------------------------------------------*/
#include <iostream>
#include "vehicle.h"
using namespace std;
vehicle::vehicle()// Constructor
{
	regisration = "";
	currentPosition = 0;
	currentSpeed = 0;
	parked = false;
	thisAction = "";
	previousAction = "";
}
vehicle::~vehicle()// Constructor
{
	regisration = "";
	currentPosition = 0;
	currentSpeed = 0;
	parked = false;
	thisAction = "";
	previousAction = "";
}
string vehicle::getRegisration() const
{
	return regisration;
}
int vehicle::getCurrentPosition() const
{
	return currentPosition;
}
int vehicle::getCurrentSpeed() const
{
	return currentSpeed;
}
bool vehicle::getParked() const
{
	return parked;
}
string vehicle::getThisAction() const
{
	return thisAction;
}
string vehicle::getPreviousAction() const
{
	return previousAction;
}
string vehicle::getType() const
{
	return type;
}
Time vehicle::getArriveTime() const
{
	return arriveTime;
}
void vehicle::setRegisration(string regisration)
{
	this->regisration = regisration;
	return;
}
void vehicle::setCurrentPosition(int currentPosition)
{
	this->currentPosition = currentPosition;
	return;
}
void vehicle::setCurrentSpeed(int currentSpeed)
{
	this->currentSpeed = currentSpeed;
	return;
}
void vehicle::setParked(bool parked)
{
	this->parked = parked;
	return;
}
void vehicle::setThisAction(string thisAction)
{
	this->thisAction = thisAction;
	return;
}
void vehicle::setPreviousAction(string previousAction)
{
	this->previousAction = previousAction;
	return;
}
void vehicle::setType(string type)
{
	this->type = type;
	return;
}
void vehicle::setArriveTime(Time arriveTime)
{
	this->arriveTime = arriveTime;
	return;
}
bool vehicle::operator< (const vehicle& rhs)
{
	if (rhs.arriveTime.hour > arriveTime.hour)
		return true;
	else if (rhs.arriveTime.hour == arriveTime.hour)
	{
		if (rhs.arriveTime.min > arriveTime.min)
			return true;
		else
			return false;
	}
	else
		return false;	
}
int vehicle::getArriveTimeHour() const
{
	return arriveTime.hour;
}
int vehicle::getArriveTimeMin() const
{
	return arriveTime.min;
}
ostream& operator << (ostream& out, const vehicle& data)
{
	out << data.getType();
        out << ":";
	out << data.getArriveTimeHour();
        out << ":";
        out << data.getArriveTimeMin();
        out << ":";
	out << data.getRegisration();
        out << ":";
	out << data.getCurrentPosition();
        out << ":";
	out << data.getCurrentSpeed();
        out << ":";
	out << data.getParked();
        out << ":";
	out << data.getThisAction();
        out << ":";
	out << data.getPreviousAction();
        out << ":";
        return out;
}
