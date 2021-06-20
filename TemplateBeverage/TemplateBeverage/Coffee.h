//
//  Coffee.h
//  TemplateBeverage
//
//  Created by hswang on 2021/6/20.
//

#ifndef Coffee_h
#define Coffee_h
class Caffee : public TemplateBeverage{
public:
    ~Caffee(){}
    void brew() override{
        std::cout<<"brewing Coffee"<<std::endl;
    }
    
    void addCondiments() override{
        std::cout<<"adding Milk into Coffee"<<std::endl;
    }
    
    bool customerWantsCondiments() override{
        std::cout<<"Do you want to add condiment into Caffee ?"<<std::endl;
        std::string c;
        std::cin>>c;
        if(c=="y"){
            return true;
        }else{
            return false;
        }
       
    }
    
};


#endif /* Coffee_h */
