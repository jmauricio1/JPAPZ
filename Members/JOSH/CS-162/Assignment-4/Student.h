#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include <string>

using namespace std;

class Student : public Person
{
private:
    int number;
public:
    Student();
    Student(string otherName, int num);
    void print();

};

#endif // STUDENT_H
