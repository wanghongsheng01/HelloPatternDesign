//
//  NYPizzaStore.h
//  FactoryPizzaFranchise
//
//  Created by hswang on 2021/6/22.
//

#ifndef NYPizzaStore_h
#define NYPizzaStore_h
#include "PizzaStore.h"
#include "Pizza.h"

class NYPizzaStore : public PizzaStore{
public:
    std::unique_ptr<Pizza> makePizza(std::string style) override{
        std::unique_ptr<Pizza> pizza = nullptr;
        
        if(style == "Cheese" ){
            pizza = std::make_unique<NYStyleCheesePizza>();
        }else if (style == "Pepperoni"){
            pizza = std::make_unique<NYStylePepperoniPizza>();
        }
        
        return pizza;
    }
};

#endif /* NYPizzaStore_h */
