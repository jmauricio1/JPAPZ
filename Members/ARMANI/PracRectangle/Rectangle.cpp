#include "Rectangle.h"

Rectangle::Rectangle()
{
height;
width;

}

Rectangle::Rectangle(double newHeight, double newWidth)
{
    height = newHeight;
    width = newWidth;

}

double Rectangle::getWidth()
{
    return width;
}

double Rectangle::getHeight()
{
    return height;
}

double Rectangle::getArea()
{
    return (width * height);
}

double Rectangle::getPerimeter()
{
    return (2 * (height + width));
}
