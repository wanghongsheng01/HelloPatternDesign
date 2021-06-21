//
//  Pizza.h
//  SampleFactoryPizza
//
//  Created by hswang on 2021/6/21.
//

#ifndef Pizza_h
#define Pizza_h
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Pizza{
public:
    virtual const string& getName()const;
    virtual void prepare()const;
    virtual void bake()const;
    virtual void cut()const;
    virtual void box()const;
    
    virtual ~Pizza()=default;
    
public:
    string Name;
    string Doue;
    string Sauce;
    vector<string>Toppings;

};




#endif /* Pizza_h */
