#ifndef VISITOR_H
#define VISITOR_H
class Bundle;
class Dog;
class Cat;
class Bird;
class Fish;

class Visitor {
public:
    virtual void VisitBundle(Bundle*) = 0;
    virtual void VisitDog(Dog*) = 0;
    virtual void VisitCat(Cat*) = 0;
    virtual void VisitBird(Bird*) = 0;
    virtual void VisitFish(Fish*) = 0;
};

#endif // VISITOR_H
