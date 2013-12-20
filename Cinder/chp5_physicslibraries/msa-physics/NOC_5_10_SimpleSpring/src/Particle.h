//
//  Particle.h
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "MSAPhysics2D.h"

class Particle {
	
public:
	Particle( msa::physics::World2D* const world, ci::Vec2f pos, bool locked );
	void display();
	void startDrag( ci::Vec2f pos );
	void endDrag();
	void drag( ci::Vec2f pos );
	
	
	ci::Vec2f					mPos;
	float						mRadius;
	msa::physics::World2D		*mWorld;
	msa::physics::Particle2D	*mParticle;
	bool						mDragging;
};