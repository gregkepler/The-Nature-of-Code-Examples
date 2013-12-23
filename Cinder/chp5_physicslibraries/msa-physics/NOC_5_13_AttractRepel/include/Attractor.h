//
//  Attractor.h
//  NOC_5_13_AttractRepel
//
//  Created by Greg Kepler on 12/22/13.
//
//

#include "cinder/app/AppNative.h"
#include "MSAPhysics2D.h"

class Attractor : public msa::physics::Particle2D {
public:
	Attractor( msa::physics::World2D* const world, ci::Vec2f loc );
	void attractParticle( msa::physics::Particle2D* const particle );
	void display();
	
	msa::physics::World2D		*mWorld;
	float						mRadius;
};