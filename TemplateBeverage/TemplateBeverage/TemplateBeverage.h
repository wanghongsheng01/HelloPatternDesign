//
//  TemplateBeverage.h
//  TemplateBeverage
//
//  Created by hswang on 2021/6/20.
//

#ifndef TemplateBeverage_h
#define TemplateBeverage_h
class TemplateBeverage{
public:
    virtual ~TemplateBeverage()=default;
    void PrepareBeverage(){
        boilWater();
        brew();
        pourCup();
        if(customerWantsCondiments()){
            addCondiments();
        }
        
    }
    
    void boilWater(){
        std::cout<<"boiling water"<<std::endl;
    }
    
    virtual void brew()=0;
    
    void pourCup(){
        std::cout<<"pouring into cup"<<std::endl;
    }
    
    virtual void addCondiments()=0;
    
    virtual bool customerWantsCondiments(){
        return true;
    }
};


#endif /* TemplateBeverage_h */
