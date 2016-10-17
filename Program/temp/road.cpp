/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 14/10/2016
-------------------------------------------------------------*/
#include <iostream>
#include "road.h"
using namespace std;
road::road()// Constructor
{
	length = 0;
	speedLimit = 0;
	parkingSpaces = 0;
	freeParkingSpaces = 0;
}
road::~road()// Constructor
{
	length = 0;
	speedLimit = 0;
	parkingSpaces = 0;
	freeParkingSpaces = 0;
}
int road::getLength() const
{
	return length;
}
int road::getSpeedLimit() const
{
	return speedLimit;
}
int road::getParkingSpaces() const
{
	return parkingSpaces;
}
int road::getFreeParkingSpaces() const
{
	return freeParkingSpaces;
}
		
void road::setLength(int length)
{
	this.length = length;
	return;
}
void road::setSpeedLimit(int speedLimit)
{
	this.speedLimit = speedLimit;
	return;
}
void road::setParkingSpaces(int parkingSpaces)
{
	this.parkingSpaces = parkingSpaces;
	return;
}
void road::setFreeParkingSpaces(int freeParkingSpaces)
{
	this.freeParkingSpaces = freeParkingSpaces;
	return;
}
