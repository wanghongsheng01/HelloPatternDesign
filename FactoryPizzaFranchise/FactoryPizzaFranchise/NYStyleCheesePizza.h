//
//  NYStyleCheesePizza.h
//  FactoryPizzaFranchise
//
//  Created by hswang on 2021/6/22.
//

#ifndef NYStyleCheesePizza_h
#define NYStyleCheesePizza_h
#include "Pizza.h"

class NYStyleCheesePizza : public Pizza{
public:
    NYStyleCheesePizza(){
        Name = "NYStyle Cheese Pizza";
        Doue = "NYStyle Cheese Pizza's Doue";
        Sauce = "NYStyle Cheese Pizza's Sauce";
        Toppings.push_back("NYStyle Cheese Pizza's topping style1");
        Toppings.push_back("NYStyle Cheese Pizza's topping style2");
    }
};

#endif /* NYStyleCheesePizza_h */
