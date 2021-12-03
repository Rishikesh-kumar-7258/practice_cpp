#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

class SHAPE{
protected:
    int width, height;
public:
    SHAPE() {width = 0; height = 0;}
    SHAPE(int a, int b) {width = a; height = b;}

    void get_data()
    {
        cout << "Enter the width of the shape: ";
        cin >> width;

        cout << "Enter the height of the shape: ";
        cin >> height;
    }

    void display_data() const{
        cout << "Width " << width << "\nHeight " << height << "\n";
    }

    void area() const{
        cout << "The area of shape is " << width * height << endl;
    }
};

class CYLINDER : public SHAPE{

public:
    CYLINDER() {width = 0; height = 0;}
    CYLINDER(int a, int b) {height = a; height = b;}

    void area() const{
        cout << "The area of the shape is " << 3.14 * pow(width, 2) * height << endl;
    }
};

class SHPERE : public SHAPE{
protected:
    SHPERE() {width = height = 0;}
    SHPERE(int r) {width = height = 2*r;}

    void get_data()
    {
        cout << "Enter the radius of the Shpere: ";
        int r;
        cin >> r;

        width = height = 2*r;
    }

    void display_data() const
    {
        cout << "The radius of the sphere is " << width / 2 << endl;
    }

    void area() const {
        cout << "The area of the shere is " << 3.14 * 4 * pow(width/2, 3) / 3 << endl;
    }

};