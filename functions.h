/* This file contains the functions to be used in the main code for the Desafio LEAD project
 The vector fullData represents all the data in sensor.log file, pushed into the vector line by line: 
 the even elements represent the timestamp and the odd elements represent the sensordata. */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string> 
using namespace std;


void modulation(int rate, vector<float> fullData)
// Process the sensor data with a modulation of <rate> times. Creates and writes results in file modulation.log

{	
	fstream file;
	file.open("modulation.log", ios::out);
	if(file.is_open())
	{
		printf("Creating modulation.log file... \n");
	}
	else 
	{
		printf("Couldn't open modulation.log file \n");
		return;
	}
	//The modulation of a vector is rate .* vector
	for (int i = 1; i<fullData.size(); i = i+2)
	{
		file << fullData[i-1] << " " << fullData[i]*rate << endl;
		
	}
	file.close();
	return;
}


void movingAverage(int numSamples, vector<float> fullData)
// Process the sensor data with a moving average of <numSamples> samples. Creates and writes results in file movingAverage.log
{
	fstream file;
	file.open("mean.log", ios::out);
	if(file.is_open())
	{
		printf("Creating mean.log file...\n ");
	}
	else 
	{
		printf("Couldn't open mean.log file \n");
		return;
	}
	//Zeros addition to fullData in order to compute the first <numSamples> movingAverage
	vector <int> zerosV (2*numSamples,0); 
	fullData.insert(fullData.begin(), zerosV.begin(), zerosV.end());
	
	//The movingAverage correspondent to the x[n] element is sum(x[n-numSamples]:x[n])/numSamples
	for (int i = 2*numSamples + 1; i<fullData.size(); i = i+2)
	{
		float sum = 0;
		for (int j = 0; j < numSamples; j++)
		{
			sum = sum + fullData[i - 2*j];
		}
		float mean = sum/numSamples;
		file << fullData[i-1] << " " << mean << endl;
		
	}
	file.close();
	return;
}

void lowPassFilter(float tau, float period, vector<float> fullData)
// Passes a low pass filter to the data with constant <tau> and sampling period <period>. Creates and writes results in file lowpass.log
{
	fstream file;
	file.open("lowpass.log", ios::out);
	if(file.is_open())
	{
		printf("Creating lowpass.log file... \n");
	}
	else 
	{
		printf("Couldn't open lowpass.log file \n");
		return;
	}
	
	//The low pass filter equation is y[k] = alpha*(u[k]+u[k+1]) - beta*y[k-1]
	float alpha = period/(2*tau + period);
	float beta = (period - 2*tau)/(period + 2*tau);
	float x = 0;
	for (int i = 1; i < fullData.size(); i = i +2)
	{
		x = alpha*(fullData[i] + fullData[i-2]) - beta*x;
		file << fullData[i-1] << " " << x << endl;
	} 
	file.close();
	return;
}
