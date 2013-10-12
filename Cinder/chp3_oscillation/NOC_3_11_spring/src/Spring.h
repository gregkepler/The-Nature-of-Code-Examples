//
//  Spring.h
//  NOC_3_11_Spring
//
//  Created by Greg Kepler on 10/7/13.
//

#pragma once
#include "cinder/app/AppBasic.h"
#include "Bob.h"

class Spring {
public:
	Spring();
	Spring(float x, float y, int l);
	
	void connect( Bob &b );
	void constrainLength( Bob &b, float minlen, float maxlen );
	void display();
	void displayLine( Bob &b );
	
private:
	ci::Vec2f mAnchor;		// Location
	
	// Rest length and spring constant
	float mLen;
	float k = 0.2;
};