//
//  TestDuck.h
//  Composition Pattern
//
//  Based on "Head First Design Patterns," Freeman & Robson, O'Reilly.
//
//  Created by HSWang on 1/6/2021.
//  Copyright © 2021 HongshengWang. All rights reserved.
//
//

#include<iostream>
#include<memory>
using namespace std;

#include "Duck.h"

int main(){
	std::unique_ptr<Duck> mimic = std::make_unique<MimicDuck>();
	mimic->perform_quack();

	return 0;
}
