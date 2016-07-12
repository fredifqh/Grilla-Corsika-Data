#include <fstream>
#include <iostream>
#include <ctime>

#include "formulas.hpp"
#include "zonification.hpp"
#include "detector.hpp"

int main(int argc, char const *argv[])
{
	srand(std::time(0));

	zonification zonification;
	formulas formula;
	detector InfodDetect;

	std::string input_file = argv[1]; // secondaries' File
	double L = atof(argv[2]);   	  // area of study of side L
	double l = atof(argv[3]);   	  // size of grilla's area
	double ndetect = atof(argv[4]);	  // Number of detectors

	std::vector<std::vector<double> > array;
	formula.read_file_function((char*)argv[1], array); // Read File and put in an array
	for (unsigned int i = 0; i < array.size(); i++)   // Zonification 
	{
		double x = array[i][4]*0.01;
		double y = array[i][5]*0.01;
		zonification.grilla(x, y, L, l); 
	}

	InfodDetect.results(ndetect, L);
	return 0;
}
