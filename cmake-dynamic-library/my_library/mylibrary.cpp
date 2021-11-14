#include "my_library.hpp"

void Tools::printHello()
{
	std::cout<<"Hello world"<<std::endl;
};


/* \method additionOfSines
*  \brief method 
*   First, operation to change from degrees to radiant. 
*   Then, for each iteration of size addition to a single variable
*/
double Tools::additionOfSines(double angleArr[], int size)
{
	//addition of the sinus
	double sumOfSines = 0;

	for(int i=0; i<size; i++)
	{
        //std::cout<<sin((angleArr[i] * PI)/180)<<std::endl;
        //Chaning from degree to radiants and then adding the result of sines
		sumOfSines += sin((angleArr[i] * PI)/180);
	}
    sumOfSines = sumOfSines/size;

    return sumOfSines;
}

/* \method additionOfCosines
*  \brief method 
*   First, operation to change from degrees to radiant. 
*   Then, for each iteration of size addition to a single variable
*/
double Tools::additionOfCosines(double angleArr[], int size)
{
    //addition of the cosinus
    double sumOfCosines = 0;

    for(int i=0; i<size; i++)
    { 
        //std::cout<<cos((angleArr[i] * PI)/180)<<std::endl;
        //Chaning from degree to radiants and then adding the result of cosine
        sumOfCosines += cos((angleArr[i] * PI)/180);
    }
    sumOfCosines = sumOfCosines/size;

    return sumOfCosines;
}

/* \method chooseCadrant
*  \brief method 
*  First, evaluate the cadrant in which the results are locate. 
*  Then, add 0 or 2PI or PI or PI
*/
double Tools::chooseCadrant(double additionSinus,double additionCosinus)
{
    double result = 0.0; 
    //addition of the cosinus
    // additionSinus and additionCosinus are POSITIVE
    if((0<=additionSinus) && (0<=additionCosinus))
    {
        result = atan(additionSinus/additionCosinus);
    }
    else if((0<=additionSinus) && (0>additionCosinus))
    {// additionSinus is  POSITIVE additionCosinus is NEGATIVE
        result = 2*PI - atan(additionSinus/additionCosinus);
    }
    else if((0>additionSinus) && (0<=additionCosinus))
    {// additionSinus is  NEGATIVE additionCosinus is POSITIVE
        result = PI - atan(additionSinus/additionCosinus);
    }
    else if((0>additionSinus) && (0>additionCosinus))
    {// additionSinus and additionCosinus are NEGATIVE
        result = PI + atan(additionSinus/additionCosinus);
    }
    else
    {
        // Nothing to do    
    }

    return result;
}

/* \method my_angle_average
*  \brief method calculating the average angles on an array
*
*/
double Tools::my_angle_average(double angleArr[], int size)
{
    double result = 0;

    std::cout<<"SinusAddition = "<<additionOfSines(angleArr,size)<<std::endl;
    std::cout<<"CosinusAddition = "<<additionOfCosines(angleArr,size)<<std::endl;

    //std::cout<<"Result = "<<result<<std::endl;
    std::cout<<"Result on degree= "<<(Tools::chooseCadrant(additionOfSines(angleArr,size),additionOfCosines(angleArr,size))*180)/PI<<"°"<<std::endl;

	return result;
}

/*
int main()
{

    double array[] = {180, 181,270};
    int sizeArray = sizeof(array)/sizeof(array[0]);
    Tools::my_angle_average(array, sizeArray);

    return 0;
}
*/
