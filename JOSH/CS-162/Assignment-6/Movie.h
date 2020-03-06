#ifndef MOVIE_H
#define MOVIE_H


class Movie
{
private:
    string title;
    Actor* actors[5];
    int numActors;
    int maxActors;
public:
    Movie();
    Movie(sttring theTitle, int numberActors);
    void addActor(Actor* person);
};

#endif // MOVIE_H
