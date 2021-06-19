//
//  Subject.h
//  ObserverWeather
//
//  Created by hswang on 2021/6/19.
//

#ifndef Subject_h
#define Subject_h
class Observer;

class Subject{
public:
    
    virtual ~Subject() = default;   
    virtual void registerObserver(Observer* o)=0;
    virtual void removeObserver(Observer* o)=0;
    virtual void notifyObserver()=0;
};


#endif /* Subject_h */
