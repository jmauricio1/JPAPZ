//Joshua Jacob Mauricio and Michael Gilbert
//This is part two of lab 1
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Hello There! This is CS 161 Lab 1, part 2." << endl;

    double tempFarenheight;
    double windSpeed;

    cout << "Now let's try to fnd the wind chiil." << endl;

    cout << "Please enter the temperature in farenheight: ";
    cin >> tempFarenheight;
    cout << " " << endl;

    cout << "Now enter the wind Speed(MPH): ";
    cin >> windSpeed;
    cout << "" << endl;

    double w = 35.74 + (0.6215 * tempFarenheight) + (-35.75 * pow(windSpeed, 0.16)) + (0.4275 * (tempFarenheight * (pow(windSpeed, 0.16))));

    cout << "The wind chill index is: " << w << endl;

}
