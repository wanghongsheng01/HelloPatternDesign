//
//  SubObserverWeather.h
//  ObserverWeather
//
//  Created by hswang on 2021/6/19.
//

#ifndef SubObserverWeather_h
#define SubObserverWeather_h

#include "Observer.h"
#include "Display.h"
#include "Subject.h"

class SubObserverWeather : public Observer, public Display{
public:
    explicit SubObserverWeather(std::shared_ptr<Subject> w):Temperature_Observer(0),
                        Humidity_Observer(0),
                        weather_data(w){
                            weather_data -> registerObserver(this);
                        }
    
    ~SubObserverWeather(){
        weather_data->removeObserver(this);
    }
    
    void update_from_subject(float temperature_notify, float humidity_notify) override{
        Temperature_Observer = temperature_notify;
        Humidity_Observer = humidity_notify;
        display();
    }
    
    void display() override{
        std::cout<<"Temperature_Observer="<<Temperature_Observer<<" 摄氏度"<<std::endl;
        std::cout<<"Humidity_Observer="<<Humidity_Observer<<" 湿度"<<std::endl;
        
    }
    
private:
    float Temperature_Observer;
    float Humidity_Observer;
    std::shared_ptr<Subject> weather_data;
    
};


#endif /* SubObserverWeather_h */
