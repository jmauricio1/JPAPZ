#include "Student.h"
#include <iostream>

Student::Student()
{

}
Student::Student(string otherName, int num)
    : Person(otherName){
    number = num;
}
void Student::print(){
    Person::print();
    cout << ", " << number << endl;
}
