//
//  main.cpp
//  TemplateBeverage
//
//  Created by hswang on 2021/6/20.
//

#include <iostream>
#include "TemplateBeverage.h"
#include "Tea.h"
#include "Coffee.h"

int main(int argc, const char * argv[]) {
    Tea* tea = new Tea();
    tea->PrepareBeverage();
    
    Caffee* caffee = new Caffee();
    caffee->PrepareBeverage();
    return 0;
}
