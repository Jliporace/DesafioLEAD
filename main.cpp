/*									MainDesafioIC.cpp

This program was created in order to solve the proposed challenge by LEAD lab and contains the following functions in functions.h:
readSensorLog(), modulation(), movingAverage(), lowPassFilter() e main().

Using the functions above, the program processes sensor data, stored in the file sensor.log, and cretaes three new files:
- modulation.log: sensor data with a 2x modulation
- mean.log: sensor data following a moving average of 20 samples
- lowpass.log: sensor data processed by a low pass filter with tau = 0.1 and sampling period 0.02

The file sensor.log has data displayed in two columns: the first element of each row corresponds to the timestamp of the information
and the second element represents the actual data acquired in that time.
*/

#include <iostream>
#include "functions.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string> 

using namespace std;


int main() {
	vector <float> fullData;
	double cell; 
	ifstream file;
	file.open("sensor.log");
	if (!file) 
	{
    	cout << "Unable to open file sensor.log";
    	exit(1);   // call system to stop
	}
	while(file >> cell)
	{
		fullData.push_back(cell);  //Write sensor.log elements into fullData vector 
	}
	file.close();
	
	/* If it is necessary to separate fullData in two vectors: timestamp[] and sensordata[] 
	int count;
	//vector <float> timestamp;
	//vector <float> sensorData;
	for (count = 0; count < fullData(); count++)
	{
		
		if(count%2 == 0)
		{
			timestamp.push_back(fullData[count]);	
		}
		else 
		{
			sensorData.push_back(fullData[count]);
		}
	} 
	double sizeData = sensorData.size();
	double sizeTimestamp = timestamp.size(); */
	bool mod = modulation(2,fullData);
	bool mov = movingAverage(20, fullData);
	bool lowpass = lowPassFilter(0.1,0.02,fullData);
	return 0;
}
