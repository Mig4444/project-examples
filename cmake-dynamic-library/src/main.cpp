#include <iostream>
#include <cstdio>
#include "my_library.hpp"

int main(int argc, char *argv[])
{
	std::cout << "Shared library" << std::endl;
	
	double array[] = {180, 181,270};
	int sizeArray = sizeof(array)/sizeof(array[0]);
   	 Tools::my_angle_average(array, sizeArray);
	
	return EXIT_SUCCESS;
}
