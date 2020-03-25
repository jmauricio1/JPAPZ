#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle
{
public:
    double width;
    double height;
    Rectangle();
    Rectangle(double newWidth, double newHeight);
    //accessors
    double getWidth();
    double getHeight();
    double getArea();
    double getPerimeter();
    //mutators
    //void setArea();
    //void setPerimeter();

};

#endif // RECTANGLE_H
