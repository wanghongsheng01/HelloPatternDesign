//
//  main.cpp
//  FactoryPizzaFranchise
//
//  Created by hswang on 2021/6/22.
//

#include <iostream>
#include "Pizza.h"
#include "ChicagoStylePepperoniPizza.h"
#include "ChicagoStyleCheesePizza .h"
#include "ChicagoStyleVeggiePizza .h"
#include "NYStyleCheesePizza.h"
#include "NYStylePepperoniPizza .h"
#include "PizzaStore.h"
#include "NYPizzaStore.h"
#include "ChicagoPizzaStore.h"
#include "PrintPizza.h"

int main(int argc, const char * argv[]) {
    std::unique_ptr<NYPizzaStore> NYstore = std::make_unique<NYPizzaStore>();
    
    std::cout<<"\n---order NYCheesePizza---\n"<<std::endl;
    std::unique_ptr<Pizza> NYCheesePizza = NYstore->orderPizza("Cheese");
    std::cout<<*NYCheesePizza;
    
    std::unique_ptr<ChicagoPizzaStore> Chicagostore = std::make_unique<ChicagoPizzaStore>();
    
    std::cout<<"\n---order ChicagoCheesePizza---\n"<<std::endl;
    std::unique_ptr<Pizza> ChicagoCheesePizza = Chicagostore->orderPizza("Cheese");
    std::cout<<*ChicagoCheesePizza;
    
    std::cout<<"\n---order ChicagoPepperoniPizza---\n"<<std::endl;
    std::unique_ptr<Pizza> ChicagoPepperoniPizza = Chicagostore->orderPizza("Pepperoni");
    std::cout<<*ChicagoPepperoniPizza;
    
    std::cout<<"\n---order ChicagoVeggiePizza---\n"<<std::endl;
    std::unique_ptr<Pizza> ChicagoVeggiePizza = Chicagostore->orderPizza("Veggie");
    std::cout<<*ChicagoVeggiePizza;
    
    
    return 0;
}
