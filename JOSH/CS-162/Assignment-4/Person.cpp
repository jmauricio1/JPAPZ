#include "Person.h"
#include <string>
#include <iostream>

using namespace std;

Person::Person()
{

}
Person::Person(string nameVal){
    name = nameVal;
}
string Person::getName(){
    return name;
}
void Person::setName(string newName){
    name = newName;
}
void Person::print(){
    cout << name;
}
