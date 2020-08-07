#include <iostream>
#include "Rectangle.h"
#include <cmath>
using namespace std;

int main()
{
    Rectangle test;
    test.width = 4;
    test.height = 40;

    cout << "The area of the rectangle is " << test.getArea() << "The perimeter of the rectangle is " << test.getPerimeter()
         << endl;

}
