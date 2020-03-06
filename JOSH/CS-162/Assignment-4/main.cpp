#include <iostream>
#include <string>

#include "Student.h"
#include "Person.h"
#include "Teacher.h"

using namespace std;

int main()
{
    Student s1("Bob", 123456);
    Student s2("Sue", 678901);
    Teacher t1("Jane", "Computer Science");

    Person* people[3];
    people[0] = &s1;
    people[1] = &s2;
    people[2] = &t1;

    for(int i = 0; i < 3; i++){
        people[i]->print();
    }
}
