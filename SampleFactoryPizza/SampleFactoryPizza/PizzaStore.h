//
//  PizzaStore.h
//  SampleFactoryPizza
//
//  Created by hswang on 2021/6/21.
//

#ifndef PizzaStore_h
#define PizzaStore_h
#include "SampleFactoryPizza.h"

class PizzaStore{
public:
    PizzaStore(SampleFactoryPizza factory){
        this->factory = factory;
    }
    
    std::unique_ptr<Pizza> orderPizza(const string& style){
        std::unique_ptr<Pizza> pizza = nullptr;
        pizza = factory.create_Pizza(style);
        
        if(pizza != nullptr){
            pizza->prepare();
            pizza->bake();
            pizza->cut();
            pizza->box();
        }
        
        return pizza;
    }
    
private:
    SampleFactoryPizza factory;
    
    
    
};

#endif /* PizzaStore_h */
