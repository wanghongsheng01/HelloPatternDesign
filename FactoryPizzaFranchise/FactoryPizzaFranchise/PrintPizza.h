//
//  PrintPizza.h
//  FactoryPizzaFranchise
//
//  Created by hswang on 2021/6/22.
//

#ifndef PrintPizza_h
#define PrintPizza_h
#include "Pizza.h"

ostream& operator<<(ostream& os, const Pizza& pizza);

ostream& operator<<(ostream& os, const Pizza& pizza){
    std::string str = pizza.getName();
    str = "\n----- " + str + " -----\n";
    str.append(pizza.Doue);
    str.append("\n");
    str.append(pizza.Sauce);
    str.append("\n");
    for(auto top : pizza.Toppings){
        str.append(top);
        str.append("\n");
    }
    str.append("\n");
        
        
    return os<<str;
}

#endif /* PrintPizza_h */
