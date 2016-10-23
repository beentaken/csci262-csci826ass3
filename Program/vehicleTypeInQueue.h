/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 15/10/2016
-------------------------------------------------------------*/
#ifndef VEHICLETYPEINQUEUE_H
#define VEHICLETYPEINQUEUE_H
#include<iostream>
#include "vehicle.h"
using namespace std;
class vehicleTypeInQueue: public vehicle
{
	public:
		vehicleTypeInQueue() : vehicle() {}
		virtual bool operator< (const vehicle&);
};
#endif
