#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>     /* atoi */
#include "Utility.h"
#include "vehicleType.h"
#include "Stats.h"
#include "road.h"
#include "activityEngine.h"
using namespace std;
bool checkRunProgramFormat(int);
int main(int argc, char *argv[])
{
	if (!checkRunProgramFormat(argc))
		return 0;
	string Vfilename = argv[1];
	string Sfilename = argv[2];
	int Days = atoi(argv[3]);

	vehicleType * Types = NULL;
	int numberOfTypeOfVehicle = 0;

	if (!readVehicleTypes(Vfilename, Types, numberOfTypeOfVehicle))
		return 0;

	Stats *Statistics = NULL;
	road roadInfo;

	int NumStatistics;
	if (!readStats(Sfilename, Statistics, NumStatistics, roadInfo))
		return 0;
		
	activityEngine activity(Days, Statistics, NumStatistics);
cout << "hahaha" << endl;
	
	activity.initHeap(Statistics);
	cout << "++++" << endl;
	cout << activity << endl;
	return 0;
}
