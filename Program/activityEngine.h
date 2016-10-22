/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 15/10/2016
-------------------------------------------------------------*/
#ifndef ACTIVITYENGINE_H
#define ACTIVITYENGINE_H
#include <iostream>
#include <string>
#include <unordered_map>
//#include "heap.h"
#include "queue.h"
#include "vehicle.h"
#include "Stats.h"
#include "vehicleType.h"
using namespace std;
class activityEngine
{
	friend ostream& operator << (ostream&, const activityEngine&);
	private:
		Queue<vehicle> **eachDayActivity;
		int **eachDayFlowEachTypeNumber;
		int days;
		int numberOfType;
	
	public:
		activityEngine();
		activityEngine(int, Stats *&, int);
		~activityEngine();
		Queue<vehicle> * getEachDayActivity(int) const;
		int getDays() const;
		double norDistribution(double, double);
		void initQueue(Stats *&, std::unordered_map<std::string, vehicleType>&);
		string generateRegisration(string, std::unordered_map<std::string, vehicleType>&);
};
#endif
