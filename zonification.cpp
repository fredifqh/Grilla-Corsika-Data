#include "zonification.hpp"
#include "formulas.hpp"

zonification::zonification(){};		
zonification::~zonification(){};

formulas name_output_file;

void zonification::grilla(double PosXpartic, double PosYpartic, double SideCuadrant, double SideGrilla) // El tamaño del cuadrante y de la grilla tiene que ser multiplo de 100
{
	if ((PosXpartic <= SideCuadrant) && (PosXpartic >= -SideCuadrant) && (PosYpartic <= SideCuadrant) && (PosYpartic >= -SideCuadrant))
	{
		if (PosXpartic >= 0)
			zona_x = int(PosXpartic/SideGrilla) + 1;
		if (PosXpartic < 0)
			zona_x = -(int(-PosXpartic/SideGrilla) + 1);
		if (PosYpartic >= 0)
			zona_y = int(PosYpartic/SideGrilla) + 1;
		if (PosYpartic < 0)
			zona_y = -(int(-PosYpartic/SideGrilla) + 1);

		name_output_file.out_file_name(zona_x, zona_y, PosXpartic, PosYpartic);
	}
	else
	{
		std::stringstream file_resto;
		file_resto << "resto.dat";
		resto.open(file_resto.str().c_str(), std::ios::app);
   		resto << PosXpartic << "  " << PosYpartic << std::endl;
		resto.close();
	}
}