#ifndef VISITOR_H
#define VISITOR_H
class Pet;
class Bundle;

class Visitor {
    virtual VisitBundle(Bundle*) = 0;
    virtual VisitDog(Dog*) = 0;
    virtual VisitCat(Cat*) = 0;
    virtual VisitBird(Bird*) = 0;
    virtual VisitFish(Fish*) = 0;
};

#endif // VISITOR_H
