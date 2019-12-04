//Joshua Jacob Mauricio and Mohammed Alhakami
//Lab 3 part 1

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a;
    double b;
    double A;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << "Enter A: ";
    cin >> A;

    const double PI = 3.14159;

    A = A * 3.14159 / 180; //Turning angle A in radians

    double sinB = (b  sin(A)) / a;
    double B = (asin(s*inB)) * 180 / PI;
    cout << "Angle B: " << round(B) << endl;

    A = A * 180 / PI;// Turning angle A from radians into degrees

    double C = 180 - B - A;
    cout << "Angle C: " << round(C) << endl;

    //CASE 2 of non-right triangle
    if (C > 90)
    {
        B = round(180 - B);
        C = round(180 - B - A);
        cout << "OR" << endl;
        cout << "Angle B: " << B << endl;
        cout << "Angle C: " << C << endl;
    }
}
