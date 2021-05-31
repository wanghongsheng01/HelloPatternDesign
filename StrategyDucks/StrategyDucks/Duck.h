//
//  Duck.h
//  StrategyDucks
//
//  Created by hswang on 2021/5/31.
//

#ifndef Duck_h
#define Duck_h

#include "FlyInterface.h"

#include <sstream>
#include <memory>

using namespace std;

/**
 member var : Each Duck has a reference* to someth*ing that implements the FlyInterface
 mem func : Rather than handling the fly behavior itself, the Duck object delegates that behavior to the object referenced by flyInterface.
 */
class Duck{
public:
    Duck(std::unique_ptr<FlyInterface> fly_ptr, std::unique_ptr<QuackInterface> quack_ptr):
            flyInterface_ptr(std::move(fly_ptr)),
            quackInterface_ptr(std::move(quack_ptr)){}
    virtual ~Duck() = default;
    
    void swim(){
        oss<<"we all can swim"<<"\n";
        
    }
    
    virtual void show()const = 0;
    
    void perform_fly() const {
        flyInterface_ptr->fly(); // Duck 引用实现 FlyInterface 接口的对象
    };
    
    void perform_quack() const {
        quackInterface_ptr->quack(); // Duck 引用实现 FlyInterface 接口的对象
    };
    
    
    
public:
    std::unique_ptr<FlyInterface> flyInterface_ptr;//Duck 对象不亲自处理 fly 行为，委托给 FlyInterface 对象
    std::unique_ptr<QuackInterface> quackInterface_ptr;
};


/**
 programming to a supertype so that the actual runtime object isn’t locked into the code.
 the declared type of the variables should be a supertype, usually an abstract class or interface, so that the objects
 assigned to those variables can be of any concrete implementation of the supertype
 */

/**
 Duck 成员变量声明为超类型 FlyInterface，实际的 runtime 对象是 FlyWithWings
 针对超类型编程，变量的声明类型应该是超类型
 */
class MallardDuck final : public Duck{
public:
    MallardDuck() : Duck(std::make_unique<FlyWithWings>(),
                         std::make_unique<Squack>()){}
    
    void show()const override{
        oss<<"I am a Mallard Duck"<<"\n";
        printf("%s", oss.str().c_str());
    }
    
};


class MuteDuck final : public Duck{
public:
    MuteDuck() : Duck(std::make_unique<FlyNoWay>(),
                      std::make_unique<FakeQuack>()){}
    
    void show() const override{
        oss<<"I am a Mute Duck"<<"\n";
    }
    
};

#endif /* Duck_h */
