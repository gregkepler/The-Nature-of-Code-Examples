//
//  Particle.h
//  NOC_5_10_SimpleSpring
//
//  Created by Greg Kepler on 12/19/13.
//
//

#include "cinder/app/AppNative.h"

class Particle {
	
public:
	Particle();
	void display();
	ci::Vec2f	mPos;
	float		mRadius;
};