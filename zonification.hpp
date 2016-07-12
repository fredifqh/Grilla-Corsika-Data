#ifndef ZONAHEADERDEF
#define ZONAHEADERDEF

#include <fstream>
#include <sstream>
#include <vector>

class zonification
{
public:
	zonification();	// constructor
	~zonification(); // destructor
	std::ofstream resto;
	int zona_x, zona_y;
	void grilla(double, double, double, double); // función prot que coloca las particulas en diferentes archivos dependiendo de su posición 
	void out_file_name(int, int, double, double);
};

#endif