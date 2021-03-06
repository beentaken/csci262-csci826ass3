#include <unordered_map>
#include "vehicleType.h"
#include "Stats.h"
#include "road.h"

bool checkRunProgramFormat(int);
//bool readVehicleTypes(string, vehicleType*&, int&);
bool readVehicleTypes(string, std::unordered_map<std::string, vehicleType>&, int&);
bool readStats(string, Stats*&, int&, road&);
//string* Tokenizer(string, char);
