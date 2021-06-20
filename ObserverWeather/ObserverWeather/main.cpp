//
//  main.cpp
//  ObserverWeather
//
//  Created by hswang on 2021/6/19.
//

#include <iostream>

#include "Subject.h"
#include "Observer.h"
#include "WeatherData.h"
#include "Display.h"
#include "SubObserverWeather.h"

using namespace std;


int main(int argc, const char * argv[]) {
    auto w = std::make_shared<WeatherData>();
    auto sub_observer_weather = std::make_shared<SubObserverWeather>(w);
    w->setMeasurements(25, 101);
    sub_observer_weather->display();
    
    return 0;
}
