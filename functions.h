/* This file contains the functions to be used in the main code for the Desafio LEAD project*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string> 
using namespace std;


bool modulation(int rate, vector<float> fullData)
// Process the sensor data with a modulation of <rate> times. Creates and writes results in file modulation.log
// The vector fullData represents all the data in sensor.log file, pushed into the vector line by line: 
// the even elements represent the timestamp and the odd elements represent sensordata.
{	
	fstream file;
	file.open("modulation.log", ios::out);
	if(file.is_open())
	{
		printf("Creating modulation.log file...");
	}
	else 
	{
		printf("Couldn't open modulation.log file'");
		return 0;
	}
	for (int i = 1; i<fullData.size(); i = i+2)
	{
		file << fullData[i-1] << " " << fullData[i]*rate << endl;
		
	}
	file.close();
	return 1;
}


bool movingAverage(int numSamples, float data[], int m)
// Process the sensor data with a moving average of <numSamples> samples. Creates and writes results in file movingAverage.log
{
	printf("Not implemented yet");
	return 0;
}

bool lowPassFilter(float tau, float period, float data[], int m)
// Passes a low pass filter to the data with constant <tau> and sampling period <period>. Creates and writes results in file lowpass.log
{
	printf("Not implemented yet");
	return 0;
}
