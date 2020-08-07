#include "Teacher.h"
#include <string>
#include <iostream>

using namespace std;

Teacher::Teacher()
{

}
Teacher::Teacher(string newName, string division)
    : Person(newName){
    div = division;
}
void Teacher::print(){
    Person::print();
    cout << ": " << div << endl;
}
