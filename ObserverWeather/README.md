## Core Code
Observer.h
```hpp
//定义观察者 Observer，负责将 class WeatherData : public Subject 数据同步到 class SubObserverWeather : public Observer
class Observer{
public:
    virtual ~Observer()=default;
    virtual void update_from_subject(float temperature, float humidity)=0; // 将 Subject 端数据同步到 Observer 端
    
};
```

Subject.h
```hpp
//  定义订阅者 Subject，定义 register/remove/notify 观察者 Observer 对象的行为
class Observer;
class Subject{
public:
    virtual ~Subject() = default;   
    virtual void registerObserver(Observer* o)=0;
    virtual void removeObserver(Observer* o)=0;
    virtual void notifyObserver()=0;
};
```

WeatherData.h
```hpp
// 定义 Subject 的具体类 WeatherData，包括实现 Subject 的 register/remove/notify 操作 Observer 行为和自身的 setMeasurements 行为
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
            o->update_from_subject(Temperature, Humidity); // 将 class WeatherData 的数据传给 class SubObserverWeather : public Observer
        }
    }
    
    void setMeasurements(float t, float h){
        Temperature = t;
        Humidity = h;
        notifyObserver(); // 只要外部更新了 class WeatherData，则触发主动更新 class SubObserverWeather : public Observer 数据
    }
    
private:
    float Temperature;
    float Humidity;
    std::unordered_set<Observer*> observers;
};
```

SubObserverWeather.h
```hpp
// 定义 Weather 观察端，将自身 register/remove 为 Observer，接收 class WeatherData : public Subject 数据
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
        std::cout<<"Temperature_Observer="<<Temperature_Observer<<"摄氏度"<<std::endl;
        std::cout<<"Humidity_Observer="<<Humidity_Observer<<"湿度"<<std::endl;
        
    }
    
private:
    float Temperature_Observer;
    float Humidity_Observer;
    std::shared_ptr<Subject> weather_data;
};

```

main.cpp
```cpp
#include <iostream>

#include "Subject.h"
#include "Observer.h"
#include "WeatherData.h"
#include "Display.h"
#include "SubObserverWeather.h"

using namespace std;

int main(int argc, const char * argv[]) {
    auto w = std::make_shared<WeatherData>();
    auto sub_observer = std::make_shared<SubObserverWeather>(w);
    w->setMeasurements(25, 101); // 外部更新 Subject 端 WeatherData，内部主动触发 Subject::notifyObserver 将数据同步到 Observer 端
    sub_observer->display();
    return 0;
}
```
## run_main_result
![image](https://user-images.githubusercontent.com/31394900/122636080-dbfb5000-d119-11eb-8366-97b074535bf6.png)


