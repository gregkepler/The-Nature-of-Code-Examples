//
//  Particle.h
//
//  Created by Greg Kepler
//  A circular particle
//

#include "cinder/app/AppNative.h"
#include <Box2D/Box2D.h>

class Particle{
public:
    Particle( b2World* const world, ci::Vec2f pos, float r );
    void		display();
	bool		done();
	void		change();
	b2Body      *mBody;
    
private:
    
    b2World		*mWorld;
    float		mRadius;
	ci::Color	mColor;
    
    void		makeBody( ci::Vec2f pos, float r );
    void		killBody();

};