//
//  Observer.h
//  ObserverWeather
//
//  Created by hswang on 2021/6/19.
//

#ifndef Observer_h
#define Observer_h

class Observer{
public:
    virtual ~Observer()=default;
    virtual void update_from_subject(float temperature, float humidity)=0;
    
};


#endif /* Observer_h */
