//
//  Particle.h
//  NOC_4_01_SingleParticle
//
//  Created by Greg Kepler on 10/12/13.
//
//

#pragma once
#include "cinder/app/AppBasic.h"

class Particle {
public:
	Particle();
	Particle( ci::Vec2f l );
	void run();
	void update();
	void display();
	bool isDead();
	
	
private:
	ci::Vec2f mLocation;
	ci::Vec2f mVelocity;
	ci::Vec2f mAcceleration;
	float mLifespan;
	
};