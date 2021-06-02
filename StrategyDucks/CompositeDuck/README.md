# Brain Power
A duck call is a device that hunters use to mimic the calls (quacks) of ducks. How would you implement your own duck call that does not inherit from the Duck class?

# Composition Pattern
>* Design Principle : Favor composition over inheritance.` HAS-A can be better than IS-A.`<br>
>* HAS-A relationship : each Duck has a FlyBehavior to which it delegates flying.<br>

>>* Favor Composition 👍🏼  When you put two classes together like this you’re using `composition`. Instead of `inheriting` their behavior, the ducks get their behavior by being composed with the right `behavior object`.

>>* Flexibility 👍🏼 As you’ve seen, creating systems using composition gives you a lot more `flexibility`. Not only does it let you `encapsulate a family of algorithms into their own set of classes`, but it also lets you `change behavior at runtime `as long as the object you’re composing with implements the correct behavior interface.<br>

# The Big Picture on encapsulated behaviors
>Okay, now that we’ve done the deep dive on the duck simulator design, it’s time to come back up for air and take a look at the big picture.

## Core Code
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
		oss<<"I mimic Quack."<<endl;
		printf("%s", oss.str().c_str());
	}

};

```
Duck.h
```hpp

#include<iostream>
#include<sstream>
#include<memory>
using namespace std;

#include "QuackInterface.h"

class Duck{
public:
	Duck(std::unique_ptr<QuackInterface> quack_inface):qt(std::move(quack_inface)){}
	virtual ~Duck() = default;
	void perform_quack(){
		qt->quack();
	}

public:
	std::unique_ptr<QuackInterface> qt;
};

class MimicDuck final : public Duck{
public:
	MimicDuck():Duck(std::make_unique<MimicQuack>()){}
	~MimicDuck(){}
};

```
TestDuck.cpp
```cpp

#include<iostream>
#include<memory>
using namespace std;

#include "Duck.h"

int main(){
	std::unique_ptr<Duck> mimic = std::make_unique<MimicDuck>();
	mimic->perform_quack();

	return 0;
}

```
