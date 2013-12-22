//
//  Particle.h
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "MSAPhysics2D.h"

class Particle : public msa::physics::Particle2D {
	
public:
	Particle( ci::Vec2f pos);
	void display();
	
	float						mRadius;
};