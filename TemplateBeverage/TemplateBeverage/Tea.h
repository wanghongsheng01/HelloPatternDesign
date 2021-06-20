//
//  Tea.h
//  TemplateBeverage
//
//  Created by hswang on 2021/6/20.
//

#ifndef Tea_h
#define Tea_h
class Tea : public TemplateBeverage{
public:
    ~Tea(){}
    void brew() override{
        std::cout<<"brewing Tea"<<std::endl;
    }
    
    void addCondiments() override{
        std::cout<<"adding Lemon into Tea"<<std::endl;
    }
    
    bool customerWantsCondiments() override{
        std::cout<<"Do you want to add condiment into Tea ?"<<std::endl;
        std::string c;
        std::cin>>c;
        if(c=="y"){
            return true;
        }else{
            return false;
        }
       
    }
    
};

#endif /* Tea_h */
