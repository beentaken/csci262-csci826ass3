#include <iostream>
#include <string>
#include <sstream>
#include "Utility.h"
using namespace std;

int main(int argc, char *argv[])
{
	if (!checkRunProgramFormat(argc))
		return 0;

    int Traffic;
    int Days;
    string Vfilename = argv[2];
    string Sfilename = argv[3];

    stringstream ss;
    ss << argv[1];
    ss >> Traffic;
    ss.str("");
    ss.clear();
    ss << argv[4];
    ss >> Days;

    vehicleType * Types = NULL;
    int NumVehicleTypes;
    Stats* Statistics = NULL;
    int NumStatistics;

    if (!readVehicleTypes(Vfilename, Types, NumVehicleTypes))
        return 0;

    if (!readStats(Sfilename, Statistics, NumStatistics, Types, NumVehicleTypes))
        return 0;

	return 0;
}
