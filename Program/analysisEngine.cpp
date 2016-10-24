#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

analysisEngine::analysisEngine()
{

}

analysisEngine::~analysisEngine()
{

}

void analysisEngine::MeasureBaseline(Queue<vehicle>** EachDay, int Days, int TotalVehicleTypes)
{
    // Outputs each days queue to its own file
    for (int i = 0; i < Days; i++) {
        string filename = "Analysis";
        string D;
        stringstream converter;
        converter << i;
        converter >> D;
        filename.append(D);
        filename.append(".csv");
        OutputToFile(EachDay[i], filename);
    }
}

bool analysisEngine::OutputToFile(Queue<vehicle>* analyse, string filename, int TotalVehicleTypes)
{
    int* TotalVehicles = new int[TotalVehicleTypes];
    float* MeanVehicleVolume = new float[TotalVehicleTypes];
    float* MeanVehicleSpeed = new float[TotalVehicleTypes];
    float* StandardDeviationVehicleVolume = new float[TotalVehicleTypes];
    float* StandardDeviationVehicleSpeed = new float[TotalVehicleTypes];
    int count = (analyse.getRear() + analyse.getMaxSizeOfQueue() - analyse.getFront()) % analyse.getMaxSizeOfQueue() + 1;
    for (int i = 0; i < count; i++) {
        int index = (analyse.getFront() + i) % analyse.getMaxSizeOfQueue(); // Index of element while travesing circularly from front
		out << analyse.queue[index] << " | ";
    }


    for (int i = 0; i < TotalVehicleTypes; i++) {
        MeanVehicleVolume[i] = MeanVehicleVolume[i]/TotalVehicles[i];
        MeanVehicleSpeed[i] = MeanVehicleSpeed[i]/TotalVehicles[i];
        // Standard Deviation Calc
    }

    ofstream myfile;
    myfile.open(filename.c_str());

    if (myfile.good()) {
        if (myfile.is_open()) {
            myfile << "VehicleType: Total-" << TotalVehicles << ", Mean Vehicle Volume-" << MeanVehicleVolume;
            myfile << "Mean Vehicle Speed-" << MeanVehicleSpeed << ", Standard Deviation Vehicle Volume-" << StandardDeviationVehicleVolume;
            myfile << "Standard Deviation Vehicle Speed-" << StandardDeviationVehicleSpeed;

            myfile.close();
        }
    }
}
