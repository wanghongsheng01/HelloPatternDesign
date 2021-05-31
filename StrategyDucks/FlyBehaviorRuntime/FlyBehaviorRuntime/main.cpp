//
//  main.cpp
//  FlyBehaviorRuntime
//
//  Created by hswang on 2021/5/31.
//

#include <iostream>
#include<memory>
#include "FlyInterface.h"
#include "QuackInterface.h"
#include "Duck.h"


using namespace std;

int main(int argc, const char * argv[]) {
    
//    cout<<"Here is MallardDuck:"<<endl;
//    unique_ptr<Duck> mallard = make_unique<MallardDuck>();
//    mallard->perform_fly();
//    mallard->swim();
//    mallard->show();
//    mallard->perform_quack();
//    cout<<"\n"<<endl;
//
//    cout<<"Here is MuteDuck:"<<endl;
//    unique_ptr<Duck> mute = make_unique<MuteDuck>();
//    mute->perform_fly();
//    mute->swim();
//    mute->show();
//    mute->perform_quack();
    
    cout<<"Quest: Imagine you want to set the duck’s behavior type through a setter method on the duck subclass, rather than by instantiating it in the duck’s constructor."<<"\n"<<endl;
    
    cout<<"Answer: To change a duck’s behavior at runtime, just call the duck’s setter method for that behavior."<<"\n"<<endl;
    
    cout<<"=== Setting flying behavior at runtime =="<<endl;
    unique_ptr<Duck> mallard2 = make_unique<MallardDuck>();
    mallard2->setFlyInterface(std::make_unique<FlyWithWings>());
    mallard2->perform_fly();
    cout<<"\n";
    
    unique_ptr<Duck> mallard3 = make_unique<MallardDuck>();
    mallard3->setFlyInterface(std::make_unique<FlyNoWay>());
    mallard3->perform_fly();
    
    
    return 0;
}
