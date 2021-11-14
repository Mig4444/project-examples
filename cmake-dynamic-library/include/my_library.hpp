#include <iostream>
#include <cmath>

#define PI 3.14159265

/** \class Tools
*   \brief method calculates average of angles
*   input array of angles
*   input size of the array
*   output returns the average angle of the incoming array
*/

class Tools
{
	public:
	static void printHello();
	static double my_angle_average(double angleArr[], int size);
    static double additionOfSines(double angleArr[], int size);
    static double additionOfCosines(double angleArr[], int size);
    static double chooseCadrant(double additionSinus,double additionCosinus);
	private:
};
