//
//  ChicagoStyleVeggiePizza .h
//  FactoryPizzaFranchise
//
//  Created by hswang on 2021/6/22.
//

#ifndef ChicagoStyleVeggiePizza__h
#define ChicagoStyleVeggiePizza__h
#include "Pizza.h"

class ChicagoStyleVeggiePizza : public Pizza{
public:
    ChicagoStyleVeggiePizza(){
        Name = "Chicago Style Veggie Pizza";
        Doue = "Chicago Style Veggie Pizza's Doue";
        Sauce = "Chicago Style Veggie Pizza's Sauce";
        Toppings.push_back("Chicago Style Veggie Pizza's topping style1");
        Toppings.push_back("Chicago Style Veggie Pizza's topping style2");
    }
};

#endif /* ChicagoStyleVeggiePizza__h */
