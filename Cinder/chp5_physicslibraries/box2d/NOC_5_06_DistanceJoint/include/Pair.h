//
//  Pair.h
//  NOC_5_06_DistanceJoint
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include <Box2D/Box2D.h>
#include "Particle.h"

class Pair {
public:
	Pair( b2World* const world, ci::Vec2f pos );
	void		display();
	
private:
	b2World     *mWorld;
	Particle	*p1, *p2;
	float		mLength;
	
};
