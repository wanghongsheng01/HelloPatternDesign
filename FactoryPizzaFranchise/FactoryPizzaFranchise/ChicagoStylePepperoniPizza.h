//
//  ChicagoStylePepperoniPizza.h
//  FactoryPizzaFranchise
//
//  Created by hswang on 2021/6/22.
//

#ifndef ChicagoStylePepperoniPizza_h
#define ChicagoStylePepperoniPizza_h
#include "Pizza.h"

class ChicagoStylePepperoniPizza : public Pizza{
public:
    ChicagoStylePepperoniPizza(){
        Name = "Chicago Style Pepperoni Pizza";
        Doue = "Chicago Style Pepperoni Pizza's Doue";
        Sauce = "Chicago Style Pepperoni Pizza's Sauce";
        Toppings.push_back("Chicago Style Pepperoni Pizza's topping style1");
        Toppings.push_back("Chicago Style Pepperoni Pizza's topping style2");
    }
};

#endif /* ChicagoStylePepperoniPizza_h */
