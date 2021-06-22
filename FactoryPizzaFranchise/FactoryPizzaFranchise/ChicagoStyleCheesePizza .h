//
//  ChicagoStyleCheesePizza .h
//  FactoryPizzaFranchise
//
//  Created by hswang on 2021/6/22.
//

#ifndef ChicagoStyleCheesePizza__h
#define ChicagoStyleCheesePizza__h
#include "Pizza.h"

class ChicagoStyleCheesePizza : public Pizza{
public:
    ChicagoStyleCheesePizza(){
        Name = "Chicago Style Cheese Pizza";
        Doue = "Chicago Style Cheese Pizza's Doue";
        Sauce = "Chicago Style Cheese Pizza's Sauce";
        Toppings.push_back("Chicago Style Cheese Pizza's topping style1");
        Toppings.push_back("Chicago Style Cheese Pizza's topping style2");
    }
};

#endif /* ChicagoStyleCheesePizza__h */
