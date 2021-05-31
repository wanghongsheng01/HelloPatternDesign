//
//  QuackInterface.h
//  StrategyDucks
//
//  Created by hswang on 2021/5/31.
//

#ifndef QuackInterface_h
#define QuackInterface_h

#include <memory>
#include <sstream>
using namespace std;


class QuackInterface {
public:
    
    QuackInterface(){}
    virtual ~QuackInterface() = default;
    virtual void quack() const = 0;
};

class Squack final : public QuackInterface{
public:
    Squack(){}
    ~Squack(){}
    void quack() const override{
        oss<<"I am a Squack Duck, I can squack"<<"\n";
        printf("%s", oss.str().c_str());
    }
};

class FakeQuack final : public QuackInterface{
public:
    FakeQuack(){}
    ~FakeQuack(){}
    void quack() const override{
        oss<<"I am a fake Duck, I can not quack"<<"\n";
        printf("%s", oss.str().c_str());
    }
};


#endif /* QuackInterface_h */
