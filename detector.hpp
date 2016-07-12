#ifndef DETECTHEADERFILE
#define DETECTHEADERFILE

#include <ctime>
#include <fstream>
#include <sstream>
#include <vector> 

class detector
{
public:
	std::ifstream zona;
	std::ofstream out;
	std::stringstream file;
	int PosTank_x, PosTank_y, limit_x, limit_y;
	void detect_info(int, int, int, int, int);
	void results(int, int);
};

#endif