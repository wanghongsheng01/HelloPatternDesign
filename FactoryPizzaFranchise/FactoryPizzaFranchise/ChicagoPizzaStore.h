//
//  ChicagoPizzaStore.h
//  FactoryPizzaFranchise
//
//  Created by hswang on 2021/6/22.
//

#ifndef ChicagoPizzaStore_h
#define ChicagoPizzaStore_h
#include "PizzaStore.h"
#include "Pizza.h"

class ChicagoPizzaStore : public PizzaStore{
public:
    std::unique_ptr<Pizza> makePizza(std::string style) override{
        std::unique_ptr<Pizza> pizza = nullptr;
        
        if(style == "Cheese" ){
            pizza = std::make_unique<ChicagoStyleCheesePizza>();
        }else if (style == "Pepperoni"){
            pizza = std::make_unique<ChicagoStylePepperoniPizza>();
        }else if (style == "Veggie"){
            pizza = std::make_unique<ChicagoStyleVeggiePizza>();
        }
        
        return pizza;
    }
};

#endif /* ChicagoPizzaStore_h */
