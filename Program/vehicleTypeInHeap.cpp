/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 15/10/2016
-------------------------------------------------------------*/
#include "vehicleTypeInHeap.h"
#include "vehicle.h"
bool vehicleTypeInHeap::operator< (const vehicle& rhs)
{
	if (currentPosition < rhs.getCurrentPosition())
		return false;
	return true;
}/*
vehicleTypeInHeap(const vehicleTypeInHeap& data)
{
	type = data.getType();
	arriveTime = data.getArriveTime();
	regisration = data.getRegisration();
	currentPosition = data.getCurrentPosition();
	currentSpeed = data.getCurrentSpeed();
	parked = data.getParked();
	thisAction = data.getThisAction();
	previousAction = data.getPreviousAction();	
}*/
