//
//  Particle.h
//  NOC_4_01_SingleParticle
//
//  Created by Greg Kepler on 8/20/13.
//
//

#pragma once

#include "cinder/app/AppBasic.h"

class Particle {
public:
	Particle();
	Particle( ci::Vec2f location );
	
	virtual void run();
	void update();
	virtual void display();
	bool isDead();

// Changed from private to protected since Particle is extended.
// protected allows subclasses to access the methods and variables.
protected:
	ci::Vec2f mLocation;
	ci::Vec2f mAcceleration;
	ci::Vec2f mVelocity;
	float mLifespan;
};