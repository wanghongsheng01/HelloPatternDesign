//
//  Pizza.h
//  FactoryPizzaFranchise
//
//  Created by hswang on 2021/6/22.
//

#ifndef Pizza_h
#define Pizza_h
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Pizza{
public:
    virtual const string& getName()const{ return this->Name; }
    
    virtual void prepare()const{
        std::cout<<"Pizza::prepare()..."<<std::endl;
        std::cout<<"preparing"<<getName()<<std::endl;
    }
    
    virtual void bake()const{
        std::cout<<"Pizza::bake()..."<<std::endl;
        std::cout<<"baking "<<getName()<<std::endl;
    }
    
    virtual void cut()const{
        std::cout<<"Pizza::cut()..."<<std::endl;
        std::cout<<"cuting "<<getName()<<std::endl;
    }
    
    virtual void box()const{
        std::cout<<"Pizza::box()..."<<std::endl;
        std::cout<<"boxing "<<getName()<<std::endl;
    }
    
    virtual ~Pizza()=default;
    
public:
    string Name;
    string Doue;
    string Sauce;
    vector<string>Toppings;

};

#endif /* Pizza_h */
