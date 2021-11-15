#include <iostream>
#include <iterator>
#include <map>

using namespace std;

/* \method calc_extrapolate
*  \brief function
*   
*   Function receives two inputs which represent two points of the curve
*   Also, a third argument is received which represent the position on x where
*   we are calculating the value on y
*/

double calc_extrapolate(map<int,int>::iterator fP, map<int,int>::iterator sP, double x)
{
    double y;
    std::cout <<"calc_extrapolate"<< std::endl;
   
    // Calculate the slope
    y = (sP->second - fP->second) / (sP->first - fP->first);

    // Calculate the new initial point, then use the previous slope
    y =  fP->second + (y *(x - fP->first));

    return y;
}
