## What
>What (is the Duck Strategy) ? <br>
> Seprate `varying` DuckBehavior Type from Duck Type
  

## Why
>Why (the Seprate Strategy is benefit to Design)? <br>
>We should NOT program to an implementation!  we are setting the behaviors to concrete classes (by `instantiating`<br>
`a behavior class like FlyWithWings` and `assigning it to our behavior reference variable`), we could easily change that<br>
at runtime dynamicly.

## How
>How (to design Strategy Pattern)?<br>
>Take a moment and think about how you would implement a duck so that its behavior could change at runtime dynamicly.<br>
>The key is that a Duck will now `delegate its flying behavior`, instead of using flying methods defined in the Duck class (or subclass).
> Since `the flyBehavior instance variable` is an interface type, we could (through polymorphism) dynamically<br>
assign a different `FlyBehavior implementation class` at runtime.

## Implement
>Add `setFlyInterface` flying behavior at runtime<br>
>Program to Duck Constructor 's Behavior object `Referenced by behaviorInterface`

## Core Code
>:joy: Duck 委托 Behavior 处理 fly 行为，通过 Behavior Inference in Duck Constructor.<br>
>:joy: Programming to a `supertype` so that `the actual runtime object isn’t locked into the code`.
        the declared type of the variables should be a supertype, usually an abstract class or interface, 
        `so that the objects assigned to those variables can be of any concrete implementation of the supertype`.<br>
        
  test.cpp
```cpp
    cout<<"Here is MallardDuck:"<<endl;
    unique_ptr<Duck> mallard = make_unique<MallardDuck>(); 
    mallard->perform_fly();
```
  impl.h
```hpp
/**
 member var : Each Duck has a reference to something that implements the FlyInterface
 mem func : Rather than handling the fly behavior itself, the Duck object delegates that behavior to the object REFERENCED by flyInterface.
 */
 
class Duck{
public:
    Duck(std::unique_ptr<FlyInterface> fly_ptr, std::unique_ptr<QuackInterface> quack_ptr):
            flyInterface_ptr(std::move(fly_ptr)),
            quackInterface_ptr(std::move(quack_ptr)){}
    virtual ~Duck() = default;
    
    void perform_fly() const {
        flyInterface_ptr->fly(); // Duck 引用实现 FlyInterface 接口的对象
    };
     
public:
    std::unique_ptr<FlyInterface> flyInterface_ptr;//Duck 对象不亲自处理 fly 行为，委托给 FlyInterface 对象
    std::unique_ptr<QuackInterface> quackInterface_ptr;
};

/**
 Duck 成员变量声明为超类型 FlyInterface，实际的 runtime 对象是 FlyWithWings
 针对超类型编程，变量的声明类型应该是超类型
 */
 
class MallardDuck final : public Duck{
public:
    MallardDuck() : Duck(std::make_unique<FlyWithWings>(),
                         std::make_unique<Squack>()){}
};

```
## Print Screen
![image](https://user-images.githubusercontent.com/31394900/120230785-a41f8c00-c282-11eb-8e80-a0dd726b1598.png)

## Syntactic
```cpp
virtual ~Duck() = default; //virtual destructor
virtual void show()const = 0; // pure virtual mem_func()

```
