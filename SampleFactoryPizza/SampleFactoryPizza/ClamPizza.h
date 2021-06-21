//
//  ClamPizza.h
//  SampleFactoryPizza
//
//  Created by hswang on 2021/6/21.
//

#ifndef ClamPizza_h
#define ClamPizza_h
#include "Pizza.h"

class ClamPizza : public Pizza{
public:
    ClamPizza(){
        Name = "Clam Pizza";
        Doue = "Clam Pizza's Doue";
        Sauce = "Clam Pizza's Sauce";
        Toppings.push_back("Clam Pizza's topping style1");
        Toppings.push_back("Clam Pizza's topping style2");
    }
};

#endif /* ClamPizza_h */
