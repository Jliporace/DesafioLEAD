/*									MainDesafioIC.cpp

This program was created in order to solve the proposed challenge by LEAD lab and contains the following functions in functions.h:
readSensorLog(), modulation(), movingAverage(), lowPassFilter() e main(). The full project is available at: https://github.com/Jliporace/DesafioLEAD

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
		
	vector <float> timestamp;
	vector <float> data;

	float fdata;
	float fcell; 
	ifstream file;
	file.open("sensor.log");
	if (!file) 
	{
    	cout << "Unable to open file sensor.log";
    	exit(1);   // call system to stop
	}
	while(file >> fcell >> fdata)
	{
		timestamp.push_back(fcell);
		data.push_back(fdata);   
	}
	file.close();
	
	
	modulation(2,timestamp, data);
	movingAverage(20, timestamp, data);
	lowPassFilter(0.1,0.02,timestamp, data);
	return 0;
}
