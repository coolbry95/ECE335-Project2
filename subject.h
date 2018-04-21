#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"
#include "itemvector.h"

class Subject {
private:
    vector<Observer*> observers;
protected:
    void attachObserver(Observer* observer){
        observers.push_back(observer);
    }

    void detachObserver(Observer* observer){
        vector<Observer*>::iterator it = find(observers.begin(), observers.end(), observer);
        if(it != observers.end()){
            observers.erase(it);
        }
    }

    void notifyObservers(){
        for(unsigned int i = 0; i < observers.size(); i++){
            observers[i]->update(this);
        }
    }

public:
    virtual ItemVector* getShoppingCart() = 0;
};
#endif // SUBJECT_H
