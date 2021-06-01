//
//  Duck.h
//  Composition Pattern
//
//  Based on "Head First Design Patterns," Freeman & Robson, O'Reilly.
//
//  Created by HSWang on 1/6/2021.
//  Copyright © 2021 HongshengWang. All rights reserved.
//

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
