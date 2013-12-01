//
//  Lollipop.h
//  NOC_5_05_MultiShapes
//
//  Created by Greg Kepler on 12/1/13.
//
//

#include "cinder/app/AppNative.h"
#include <Box2D/Box2D.h>

class Lollipop{
public:
	Lollipop( b2World* const world, ci::Vec2f pos );
	void		display();
	bool		done();
	
private:
	b2World		*mWorld;
	b2Body      *mBody;
	float		mWidth, mHeight, mRadius;
	
	void		makeBody( ci::Vec2f pos );
    void		killBody();

};