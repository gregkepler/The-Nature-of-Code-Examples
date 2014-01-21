//
//  Rule.h
//
//  Created by Greg Kepler
//
//  LSystem Rule class
//

#pragma once

class Rule {
	char a;
	std::string b;
	
public:
	Rule( char a_, std::string b_ ){
		a = a_;
		b = b_;
	};
	
	char getA(){ return a; }
	std::string getB(){ return b; }
};

