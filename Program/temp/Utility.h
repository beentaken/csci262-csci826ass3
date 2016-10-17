#include "VehicleType.h"
#include "Stats.h"

bool checkRunProgramFormat(int);
bool readVehicleTypes(string, vehicleType*&, int&);
bool readStats(string, Stats*, int&, vehicleType*, int);
string* Tokenizer(string, char);
bool VehicleTypeExist(vehicleType*, int, string, int&);
