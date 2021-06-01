//
//  QuackInterface.h
//  Composition Pattern
//
//  Based on "Head First Design Patterns," Freeman & Robson, O'Reilly.
//
//  Created by HSWang on 1/6/2021.
//  Copyright © 2021 HongshengWang. All rights reserved.
//
//

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
