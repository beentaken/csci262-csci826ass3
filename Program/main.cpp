#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>     /* atoi */
#include <unordered_map>
#include "Utility.h"
#include "vehicleType.h"
#include "Stats.h"
#include "road.h"
#include "activityEngine.h"
using namespace std;
int main(int argc, char *argv[])
{
	if (!checkRunProgramFormat(argc))
		return 0;
	string Vfilename = argv[1];
	string Sfilename = argv[2];
	int Days = atoi(argv[3]);

	std::unordered_map<std::string, vehicleType> Types;
	int numberOfTypeOfVehicle = 0;

	if (!readVehicleTypes(Vfilename, Types, numberOfTypeOfVehicle))
		return 0;
	
	Stats *Statistics = NULL;
	road roadInfo;

	int NumStatistics;
	if (!readStats(Sfilename, Statistics, NumStatistics, roadInfo))
		return 0;
		
	activityEngine activity(Days, Statistics, NumStatistics);	
	activity.initQueue(Statistics, Types);
	
	//cout << activity << endl;
	activity.simulation(Types, roadInfo);
	return 0;
}
