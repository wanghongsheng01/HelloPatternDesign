//
//  SampleFactoryPizza.h
//  SampleFactoryPizza
//
//  Created by hswang on 2021/6/21.
//

#ifndef SampleFactoryPizza_h
#define SampleFactoryPizza_h
#include "Pizza.h"

class SampleFactoryPizza{
public:
    std::unique_ptr<Pizza> create_Pizza(const string& style){
        
        std::unique_ptr<Pizza> pizza = nullptr;
        
        if(style == "Cheese"){
            pizza = std::make_unique<CheesePizza>();
        }
        else if (style == "Clam"){
            pizza = std::make_unique<ClamPizza>();
        }
        
        return pizza;
    }
};

#endif /* SampleFactoryPizza_h */
