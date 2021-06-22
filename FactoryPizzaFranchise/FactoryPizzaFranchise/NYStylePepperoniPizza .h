//
//  NYStylePepperoniPizza .h
//  FactoryPizzaFranchise
//
//  Created by hswang on 2021/6/22.
//

#ifndef NYStylePepperoniPizza__h
#define NYStylePepperoniPizza__h
#include "Pizza.h"

class NYStylePepperoniPizza : public Pizza{
public:
    NYStylePepperoniPizza(){
        Name = "NYStyle Pepperoni Pizza";
        Doue = "NYStyle Pepperoni Pizza's Doue";
        Sauce = "NYStyle Pepperoni Pizza's Sauce";
        Toppings.push_back("NYStyle Pepperoni Pizza's topping style1");
        Toppings.push_back("NYStyle Pepperoni Pizza's topping style2");
    }
};

#endif /* NYStylePepperoniPizza__h */
