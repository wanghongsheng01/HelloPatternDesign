## SampleFacatoryPizza Design Graph
![image](https://user-images.githubusercontent.com/31394900/122785632-1d405b00-d2e6-11eb-9d9f-cb5508cb1979.png)

* 客户从 PizzaStore 对象中 `orderPizza(const string& style)`
* PizzaStore::orderPizza(const string& style) 利用 SampleFactoryPizza 类型成员来产出 Pizza 对象 `pizza = factory.create_Pizza(style)`
* SampleFactoryPizza::createPizza(const string& style) 产出各种 style 的 Pizza

## Note
SampleFactoryPizza.h
```h
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
```
使用 class SampleFactoryPizza 时，只需声明 SampleFactoryPizza factory，不用 `new` 一个对象，因为 class SampleFactoryPizza 无构造函数。
