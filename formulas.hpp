#ifndef FORMHEADERFILE
#define FORMHEADERFILE

#include <fstream>
#include <sstream>
#include <cmath>
#include <iostream>
#include <vector> 

class formulas
{
public:
	formulas(); // constructor
	~formulas(); // destructor
	std::ofstream zonasFile;
	void read_file_function(char*, std::vector<std::vector<double> >&);
	double distan(double, double, double, double); // Function to determine the distant between two points
	double rand_number(double); // Function to get rand numbers
	void out_file_name(int, int, double, double); // Function to write out files
};
#endif
