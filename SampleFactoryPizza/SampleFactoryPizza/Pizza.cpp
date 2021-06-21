//
//  Pizza.cpp
//  SampleFactoryPizza
//
//  Created by hswang on 2021/6/21.
//

#include <stdio.h>
#include "Pizza.h"
#include <iostream>
#include <sstream>

const std::string& Pizza::getName()const{
    return this->Name;
}

void Pizza::prepare()const{
    std::cout<<"Pizza::prepare()..."<<std::endl;
    std::cout<<"preparing"<<getName()<<std::endl;
}

void Pizza::bake()const{
    std::cout<<"Pizza::bake()..."<<std::endl;
    std::cout<<"baking "<<getName()<<std::endl;
}

void Pizza::cut()const{
    std::cout<<"Pizza::cut()..."<<std::endl;
    std::cout<<"cuting "<<getName()<<std::endl;
}

void Pizza::box()const{
    std::cout<<"Pizza::box()..."<<std::endl;
    std::cout<<"boxing "<<getName()<<std::endl;
}






