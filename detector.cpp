#include <iostream>

#include "detector.hpp"
#include "formulas.hpp"

formulas formula;

void detector::detect_info(int x, int y, int PosTank_x, int PosTank_y, int f)	
{
	std::stringstream file_detector; // Declaring a variable file_detector to store a word sequence, which is shown below
	file_detector << "zona_" + std::to_string(x) + "_zona_" + std::to_string(y) +  ".dat"; // Word sequence stored in file_detector variable
	std::ifstream zona(file_detector.str().c_str()); // Giving permission to open the file using the variable file_detector
	
	std::cout << file_detector.str().c_str() << std::endl;

	std::stringstream out_file; 
	out_file << "detector_n°" + std::to_string(f) + ".dat"; 
	out.open(out_file.str().c_str(), std::ios::app);

// The next commands able to get the results in scientific notation

	out.setf(std::ios::scientific);
	out.setf(std::ios::showpos);
	out.precision(5);
//
	std::vector<std::vector<double> > zona1;
	formula.read_file_function((char*) file_detector.str().c_str(), zona1);
		for (unsigned int q = 0; q < zona1.size(); ++q)
			if (formula.distan(zona1[q][0], zona1[q][1], PosTank_x, PosTank_y) <= 3)
			{
				std::cout << zona1[q][0] << "    " << zona1[q][1] << std::endl;
				out << zona1[q][0] << "    " << zona1[q][1] << std::endl;
			}	
	zona.close();
	out.close();
}

void detector::results(int ndetect, int L)
{
	for (int  f = 1; f <= ndetect; ++f)
	{
		/*
		PosTank_x = formula.rand_number(L);
		if (PosTank_x >= 0)
			limit_x = int(PosTank_x/100) + 1;
		else 
			limit_x = int(PosTank_x/100) - 1;

		PosTank_y = formula.rand_number(L);
		if (PosTank_y >= 0)
			limit_y = int(PosTank_y/100) + 1;
		else 
			limit_y = int(PosTank_y/100) - 1;

		std::cout << PosTank_x << "  " << PosTank_y << std::endl;
		std::cout << limit_x << "  " << limit_y << std::endl;
		*/
		PosTank_x = 22;
		PosTank_y = 28;
		
		limit_x = 1;
		limit_y = 1;

		//if (PosTank_x > 0 && PosTank_y > 0)
		//{		
			if (PosTank_x + 3 >= (limit_x*100 - 100) && PosTank_x + 3 <= limit_x*100 && PosTank_y + 3 >= (limit_y*100 - 100) && PosTank_y + 3 <= limit_y*100)
			{
				detector::detect_info(limit_x, limit_y, PosTank_x, PosTank_y, f);
			}
			else if (PosTank_x + 3 >= (limit_x*100 - 100) && PosTank_x + 3 > limit_x*100 && PosTank_y + 3 >= (limit_y*100 - 100) && PosTank_y + 3 <= limit_y*100)
			{
				detector::detect_info(limit_x, limit_y, PosTank_x, PosTank_y, f);
				detector::detect_info(limit_x + 1, limit_y, PosTank_x, PosTank_y, f);
			}
			else if (PosTank_x + 3 >= (limit_x*100 - 100) && PosTank_x + 3 <= limit_x*100 && PosTank_y + 3 >= (limit_y*100 - 100) && PosTank_y + 3 > limit_y*100)
			{
				detector::detect_info(limit_x, limit_y, PosTank_x, PosTank_y, f);
				detector::detect_info(limit_x, limit_y + 1, PosTank_x, PosTank_y, f);
			}
			else if (PosTank_x + 3 >= (limit_x*100 - 100) && PosTank_x + 3 > limit_x*100 && PosTank_y + 3 >= (limit_y*100 - 100) && PosTank_y + 3 > limit_y*100)
			{
				detector::detect_info(limit_x, limit_y, PosTank_x, PosTank_y, f);
				detector::detect_info(limit_x + 1, limit_y, PosTank_x, PosTank_y, f);
				detector::detect_info(limit_x, limit_y + 1, PosTank_x, PosTank_y, f);
				detector::detect_info(limit_x + 1, limit_y + 1, PosTank_x, PosTank_y, f);
			} 
		//}
		//else if (PosTank_x < 0 && PosTank_y > 0)
		//{}

	}
}