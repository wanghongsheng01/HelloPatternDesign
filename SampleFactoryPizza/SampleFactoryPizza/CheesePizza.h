//
//  CheesePizza.h
//  SampleFactoryPizza
//
//  Created by hswang on 2021/6/21.
//

#ifndef CheesePizza_h
#define CheesePizza_h
#include "Pizza.h"

class CheesePizza : public Pizza{
public:
    CheesePizza(){
        Name = "CheesePizza";
        Doue = "Cheese Pizza's Doue";
        Sauce = "Cheese Pizza's Sauce";
        Toppings.push_back("Cheese Pizza's topping style1");
        Toppings.push_back("Cheese Pizza's topping style2");
    }
};

#endif /* CheesePizza_h */
