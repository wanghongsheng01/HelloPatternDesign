## Quest 

> Imagine you want to set the duck’s behavior type through a setter method on the duck subclass, rather than by instantiating it in the duck’s constructor.
     
     

## Answer 

>To change a duck’s behavior at runtime, just call the duck’s setter method for that behavior.

## Implement
>Add `setFlyInterface` flying behavior at runtime

## Core Code
  test.cpp
```cpp
    cout<<"Quest: Imagine you want to set the duck’s behavior type through a setter method on the duck subclass, rather than by instantiating it in the duck’s constructor."<<"\n"<<endl;
    
    cout<<"Answer: To change a duck’s behavior at runtime, just call the duck’s setter method for that behavior."<<"\n"<<endl;
    
    cout<<"=== Instantiating fly behavior type in the duck’s constructor at compile time =="<<endl;
    unique_ptr<Duck> mallard = make_unique<MallardDuck>(); // Instantiate Duck's constructor in the duck subclass
    mallard->perform_fly();
    cout<<"Instantiating fly behavior type in the duck’s constructor at compile time!\n"<<endl;
    
    
    cout<<"=== Setting flying behavior at runtime =="<<endl;
    unique_ptr<Duck> mallard2 = make_unique<MallardDuck>();
    mallard2->setFlyInterface(std::make_unique<FlyWithWings>());
    mallard2->perform_fly();
    cout<<"Setting flying behavior at runtime!\n"<<endl;
    
    unique_ptr<Duck> mallard3 = make_unique<MallardDuck>();
    mallard3->setFlyInterface(std::make_unique<FlyNoWay>());
    mallard3->perform_fly();
    cout<<"Setting flying behavior at runtime!\n"<<endl;
```
  impl.h
```hpp
class Duck{
public:
    Duck(std::unique_ptr<FlyInterface> fly_ptr, std::unique_ptr<QuackInterface> quack_ptr):
            flyInterface_ptr(std::move(fly_ptr)),
            quackInterface_ptr(std::move(quack_ptr)){}
    virtual ~Duck() = default;
    void setFlyInterface(std::unique_ptr<FlyInterface> flyInterface){
        flyInterface_ptr = std::move(flyInterface);
    }
    void perform_fly() const {
        flyInterface_ptr->fly(); // Duck 类委托 FlyInterface 类对象处理 fly 行为
    };
 
public:
    std::unique_ptr<FlyInterface> flyInterface_ptr;//Duck 对象不亲自处理 fly 行为，委托给 FlyInterface 对象
};

```
## Print Screen
![image](https://user-images.githubusercontent.com/31394900/120225242-754fe880-c277-11eb-9281-418fef1f791a.png)


public:
