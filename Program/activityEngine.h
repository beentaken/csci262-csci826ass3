/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 15/10/2016
-------------------------------------------------------------*/
#ifndef ACTIVITYENGINE_H
#define ACTIVITYENGINE_H
#include <iostream>
#include <string>
#include "heap.h"
//#include "heap.cpp"
#include "vehicle.h"
#include "Stats.h"
using namespace std;
class activityEngine
{
	friend ostream& operator << (ostream&, const activityEngine&);
	private:
		Heap<vehicle> **eachDayActivity;
		int **eachDayFlowEachTypeNumber;
		int days;
		int numberOfType;
	
	public:
		activityEngine();
		activityEngine(int, Stats *&, int);
		~activityEngine();
		Heap<vehicle> * getEachDayActivity(int) const;
		int getDays() const;
		double norDistribution(double, double);
		void initHeap(Stats *&);
};
#endif
