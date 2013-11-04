//
//  Particle.h
//  NOC_4_01_SingleParticle
//
//  Created by Greg Kepler on 8/20/13.
//
//

#include "cinder/app/AppBasic.h"

class Particle {
public:
	Particle();
	Particle( ci::Vec2f location );
	
	void run();
	void applyForce( ci::Vec2f force );
	void update();
	void display();
	bool isDead();
	
private:
	ci::Vec2f mLocation;
	ci::Vec2f mAcceleration;
	ci::Vec2f mVelocity;
	float mMass;
	float mLifespan;
};