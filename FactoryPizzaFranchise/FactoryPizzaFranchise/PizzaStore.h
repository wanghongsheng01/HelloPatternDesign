//
//  PizzaStore.h
//  FactoryPizzaFranchise
//
//  Created by hswang on 2021/6/22.
//

#ifndef PizzaStore_h
#define PizzaStore_h
#include "Pizza.h"
#include <string>
#include <memory>
using namespace std;

class PizzaStore{
public:
    virtual ~PizzaStore()=default;
    
    virtual std::unique_ptr<Pizza> makePizza(std::string style)=0;
    
    std::unique_ptr<Pizza> orderPizza(std::string style){
        std::unique_ptr<Pizza> pizza = nullptr;
        pizza = makePizza(style);
        
        if(pizza!=nullptr){
            pizza->prepare();
            pizza->bake();
            pizza->cut();
            pizza->box();
        }
        
        return pizza;
    }
};

#endif /* PizzaStore_h */
