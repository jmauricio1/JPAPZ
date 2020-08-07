#ifndef TEACHER_H
#define TEACHER_H
#include "Person.h"
#include <string>

class Teacher : public Person
{
private:
    string div;
public:
    Teacher();
    Teacher(string newName, string division);
    void print();
};

#endif // TEACHER_H
