//
//  main.cpp
//  SampleFactoryPizza
//
//  Created by hswang on 2021/6/21.
//

#include <iostream>
#include "Pizza.h"
#include "CheesePizza.h"
#include "ClamPizza.h"
#include "SampleFactoryPizza.h"
#include "PizzaStore.h"
#include "PrintPizza.h"

int main(int argc, const char * argv[]) {
    
    SampleFactoryPizza factory; // 声明 SampleFactoryPizza 对象 factory
    PizzaStore pizzaStore(factory); // 客户 PizzaStore 对象消费 factory 对象
    
    std::unique_ptr<Pizza> pizza_cheese = pizzaStore.orderPizza("Cheese");
    std::cout<<pizza_cheese->getName()<<std::endl;
    std::cout<<*pizza_cheese;
    
    std::unique_ptr<Pizza> pizza_clam = pizzaStore.orderPizza("Clam");
    std::cout<<pizza_clam->getName()<<std::endl;
    std::cout<<*pizza_clam;
    
    return 0;
}
