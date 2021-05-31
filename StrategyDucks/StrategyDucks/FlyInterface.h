//
//  FlyInterface.h
//  StrategyDucks
//
//  Created by hswang on 2021/5/31.
//

#ifndef FlyInterface_h
#define FlyInterface_h

#include<sstream>
using namespace std;
std::ostringstream oss;

class FlyInterface{
public:
    FlyInterface(){}
    
    
    virtual void fly() const = 0;
    virtual ~FlyInterface()=default;
};

class FlyWithWings final : public FlyInterface{
public:
    FlyWithWings(){}
    
    
    void fly() const override{
        oss<<"I am flying "<<"\n";
        printf("%s", oss.str().c_str());
    }
    
    ~FlyWithWings(){}
    
};

class FlyNoWay final : public FlyInterface{
public:
    FlyNoWay(){}
    
    
    void fly() const override{
        oss<<"I can not fly"<<"\n";
        printf("%s", oss.str().c_str());
    }
    
    ~FlyNoWay(){}
    
};

#endif /* FlyInterface_h */
