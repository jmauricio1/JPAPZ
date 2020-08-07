#ifndef ACTOR_H
#define ACTOR_H


class Actor
{
private:
    string firstName;
    string lastName;
    int birthYear;
public:
    Actor();
    Actor(string fName, string lName, int bYear);
    string getInfo();
};

#endif // ACTOR_H
