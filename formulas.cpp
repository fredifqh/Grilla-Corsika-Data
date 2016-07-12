#include "formulas.hpp"

formulas::formulas(){};
formulas::~formulas(){};

void formulas::read_file_function(char* FileSecundarios, std::vector<std::vector<double> >& array)
{
	std::ifstream input;
    input.open(FileSecundarios);
    if(input.is_open())
    {
        if (input){
			std::string line;
			while (getline(input, line)){
				if (line[0] != '#'){
					array.push_back(std::vector<double>());
					std::stringstream split(line);
					double value;
					while (split >> value){
						array.back().push_back(value);
					}			
				}
			}
		}
	}
	input.close();
}

double formulas::distan(double PostParti_x, double PostParti_y, double PostTanq_x, double PostTanq_y)
{
	return sqrt(pow(PostParti_x - PostTanq_x, 2) + pow(PostParti_y - PostTanq_y, 2));
}

double formulas::rand_number(double L)
{
	return (rand() % (int)(2*L + 1)) - 2*L/2;
}

void formulas::out_file_name(int etiqueX, int etiqueY, double PosXpartic, double PosYpartic)
{
	std::stringstream out_filename;
	out_filename << "zona_" + std::to_string(etiqueX) + "_zona_" + std::to_string(etiqueY) +  ".dat";
	zonasFile.setf(std::ios::scientific);
	zonasFile.setf(std::ios::showpos);
	zonasFile.precision(5);
   	zonasFile.open(out_filename.str().c_str(), std::ios::app);
   	zonasFile << PosXpartic << "  " << PosYpartic << std::endl;
	zonasFile.close();
}