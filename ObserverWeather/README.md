## Core Code

Subject 端功能：订阅端 Subject 负责注册/删除 Observer 用户，以及将订阅端数据同步到观察端
* 由于需用 Observer 对象主动获取订阅端的成员变量，故订阅端需有 std::unordered_set<Observer*> （Observer集合）类型成员
* 由于订阅端 Subject::notifyObserver()需将`订阅端`数据同步到 Observer 端，故需借助 Observer 对象的同步功能 `Observer 对象的 update_from_subject(订阅端成员变量)行为`

Subject.h
```h
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
```h
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
Observer 端功能：负责提供 Observer 对象从 Subject 端主动获取 Subject 成员变量的方法
* 由于观察端需从 Subject 端获取 Subject 端的成员变量，故观察端需有 `update_from_subject(订阅端成员变量的形参)`
* 由于观察端需接收订阅端的成员变量，故观察端需定义与订阅端同名的成员变量，用来接收订阅端同步过来的数据 `Temperature_Observer` 和 `Humidity_Observer`  
* 由于观察端需将自己注册(或删除)成为一个 Observer，且因订阅端负责注册 Observer，故观察端需有 Subject 类型的成员变量 `std::shared_ptr<Subject>`  

Observer.h
```h
//定义观察者 Observer，负责将 class WeatherData : public Subject 数据同步到 class SubObserverWeather : public Observer
class Observer{
public:
    virtual ~Observer()=default;
    virtual void update_from_subject(float temperature, float humidity)=0; // 将 Subject 端数据同步到 Observer 端
    
};
```
观察端的子观察员 class SubObserverWeather : public Observer
* class SubObserverWeather 类使用的 std::shared_ptr
* explicit 显式构造，只有一个非默认参数 `std::shared_ptr<Subject>`
* explicit 当除了第一个参数以外的其他参数都有默认值的时候, explicit关键字依然有效, 此时, 当调用构造函数时只传入一个参数, 等效于只有一个参数的类构造函数
* explicit关键字的作用就是防止类构造函数的隐式自动转换，explicit的优点是可以避免不合时宜的类型变换
* 被声明为explicit的构造函数通常比其non-explicit兄弟更受欢迎。因为它们禁止编译器执行非预期（往往也不被期望）的类型转换

SubObserverWeather.h
```h
// 定义 Weather 观察端，将自身 register/remove 为 Observer，接收 class WeatherData : public Subject 数据
#include "Observer.h"
#include "Display.h"
#include "Subject.h"

class SubObserverWeather : public Observer, public Display{
public:
    explicit SubObserverWeather(std::shared_ptr<Subject> w):Temperature_Observer(0),
                        Humidity_Observer(0),
                        subject_weather(w){
                            subject_weather -> registerObserver(this);
                        }
    
    ~SubObserverWeather(){
        subject_weather->removeObserver(this);
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
    std::shared_ptr<Subject> subject_weather;
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


