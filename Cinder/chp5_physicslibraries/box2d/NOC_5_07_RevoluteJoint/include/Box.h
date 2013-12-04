//
//  Box.h
//  NOC_5_07_RevoluteJoint
//
//  Created by Greg Kepler on 12/3/13.
//
//

#include "cinder/app/AppNative.h"
#include <Box2D/Box2D.h>

class Box {
public:
	Box( b2World* const world, ci::Vec2f pos, float w, float h, bool lock );
	void		display();
	b2Body		*mBody;
	
private:
	void		killBody();
	b2World		*mWorld;
	float		mWidth, mHeight;
};