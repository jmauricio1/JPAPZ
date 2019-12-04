#ifndef ACTORLIST_H
#define ACTORLIST_H
#include "Actor.h"


class ActorList
{
private:
    Actor actors[5];
    int numActors;
public:
    ActorList();
    ActorList(ActorList& otherList);
    Actor* getActorByIndex(int n);
};

#endif // ACTORLIST_H
