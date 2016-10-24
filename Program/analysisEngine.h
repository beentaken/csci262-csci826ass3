/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 15/10/2016
-------------------------------------------------------------*/
#ifndef ANALYSISENGINE_H
#define ANALYSISENGINE_H
#include<iostream>
#include <string>
#include "queue.h"
#include "vehicle.h"
using namespace std;
class analysisEngine
{
	private:

	public:
		analysisEngine();
		~analysisEngine();
		void MeasureBaseline(Queue<vehicle>**, int, int);
		bool OutputToFile(Queue<vehicle>*, string, int);
}
#endif
