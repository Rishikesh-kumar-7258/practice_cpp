/*
Modify the class and the program of exercise 5.2.
Such that the program would be able to add two vectors and display the resultant vector.

*@file - q5.cpp
*@author - Rishikesh Kumar
*/

#include <iostream>
using namespace std;

class DM{

private:
    float meter, centimeter;
public:
    DM(float, float);

    friend DM addition(DB val);
    void display() const;

};

class DB{

private:
    float feet, inches;
public:
    DB(float,float);

    friend DB addition(DM val);
    void display() const;
};


// main function
int main()
{

    return 0;
}

DM addition(DB val)
{
    float a = val.feet;
    float b = val.inches;

    a *= 0.3048;
    b *= 2.54;

    float total = a*100 + b;

}

DM :: DM(float a, float b)
{
    meter = a;
    centimeter = b;
}

DB :: DB(float a, float b)
{
    feet = a;
    inches = a;
}