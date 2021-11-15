#include <iostream>

int main()
{
    // Map container composed by the values of X and Y of a curve
    map<int,int> data;

    data.insert(pair<int,int>(4,80));
    data.insert(pair<int,int>(6,90));

    map<int,int>::iterator firstPoint = data.begin();
    map<int,int>::iterator secondPoint = data.find(6);

    double x = 5;

    cout << "Value of y ("<< x<< ") = " << calc_extrapolate(firstPoint,secondPoint, x) << endl;
    return 0;
}
