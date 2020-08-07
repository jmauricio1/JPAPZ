#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
private:
    string name;
public:
    Person();
    Person(string nameVal);
    string getName();
    void setName(string newName);
    virtual void print();
};

#endif // PERSON_H
