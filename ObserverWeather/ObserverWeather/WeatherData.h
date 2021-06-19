//
//  WeatherData.h
//  ObserverWeather
//
//  Created by hswang on 2021/6/19.
//

#ifndef WeatherData_h
#define WeatherData_h

#include "Subject.h"
#include "Observer.h"

#include <unordered_set>

class WeatherData : public Subject{
    
public:
    void registerObserver(Observer* o) override{
        observers.insert(o);
    }
    
    void removeObserver(Observer* o) override{
        observers.erase(o);
    }
    
    void notifyObserver() override{
        for(auto o:observers){
            o->update_from_subject(Temperature, Humidity);
        }
    }
    
    void setMeasurements(float t, float h){
        Temperature = t;
        Humidity = h;
        notifyObserver();
    }
    
private:
    float Temperature;
    float Humidity;
    std::unordered_set<Observer*> observers;
};

#endif /* WeatherData_h */
