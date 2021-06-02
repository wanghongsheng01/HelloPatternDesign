# Setting behavior dynamically
set the duck’s behavior type through a setter method on the duck subclass instead of instantiating it in the duck’s constructor.

## Core Code
Duck.h
```hpp

#include<iostream>
#include<sstream>
#include<memory>
using namespace std;

#include "QuackInterface.h"

class Duck{
public:
	Duck(){}
	virtual ~Duck() = default;

	void SetBehaviorInterface(std::unique_ptr<QuackInterface> quack_inface){
		qt = std::move(quack_inface);
	}

	void perform_quack(){
		qt->quack();
	}

public:
	std::unique_ptr<QuackInterface> qt;
};

class MimicDuck final : public Duck{
public:
	MimicDuck():Duck(){}
	~MimicDuck(){}
};

```

TestDuck.h
```cpp

#include<iostream>
#include<memory>
using namespace std;

#include "Duck.h"

int main(){
	std::unique_ptr<Duck> mimic1 = std::make_unique<MimicDuck>();
	mimic1->SetBehaviorInterface(std::make_unique<MimicQuack>());
	mimic1->perform_quack();

	std::unique_ptr<Duck> mimic2 = std::make_unique<MimicDuck>();
	mimic2->SetBehaviorInterface(std::make_unique<CallQuack>());
	mimic2->perform_quack();

	return 0;
}

```

QuackInterface.h
```hpp

#include<iostream>
#include<sstream>
using namespace std;

ostringstream oss;

class QuackInterface{
public:
	QuackInterface(){};
	virtual ~QuackInterface() = default;

	virtual void quack() const = 0;
	
};

class MimicQuack final : public QuackInterface{
public:
	MimicQuack(){}
	~MimicQuack(){}
	void quack() const override{
		oss<<"mimicing Quack Duck."<<endl;
		printf("%s", oss.str().c_str());
	}

};

class CallQuack final : public QuackInterface{
public:
	CallQuack(){}
	~CallQuack(){}
	void quack() const override{
		oss<<"calling Quack Duck."<<endl;
		printf("%s", oss.str().c_str());
	}

};

```
## Printf Test Results
* command line (`NOTE` : -std=c++14)
> `g++ TestDuck.cpp -std=c++14 -Wall -o main`
>  `./main`

* display <br>

![image](https://user-images.githubusercontent.com/31394900/120362969-39338b00-c33e-11eb-95a6-1cef844da833.png)

