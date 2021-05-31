//
//  main.cpp
//  StrategyDucks
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
    // insert code here...
    cout<<"Here is MallardDuck:"<<endl;
    unique_ptr<Duck> mallard = make_unique<MallardDuck>();
    mallard->perform_fly();
    mallard->swim();
    mallard->show();
    mallard->perform_quack();
    cout<<"\n"<<endl;
    
    cout<<"Here is MuteDuck:"<<endl;
    unique_ptr<Duck> mute = make_unique<MuteDuck>();
    mute->perform_fly();
    mute->swim();
    mute->show();
    mute->perform_quack();
    
    std::cout <<"\n"<< "Hello, World!\n";
    return 0;
}
