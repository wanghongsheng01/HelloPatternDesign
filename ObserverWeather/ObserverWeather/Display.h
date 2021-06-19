//
//  Display.h
//  ObserverWeather
//
//  Created by hswang on 2021/6/19.
//

#ifndef Display_h
#define Display_h

class Display{
public:
    
    virtual ~Display() = default;
    virtual void display() = 0;
};

#endif /* Display_h */
