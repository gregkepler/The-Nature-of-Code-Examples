//
//  Particle.h
//  NOC_5_03_ChainShape_SimpleApp
//
//  Created by Greg Kepler
//  A circular particle
//

#include "cinder/app/AppNative.h"
#include <Box2D/Box2D.h>

class Particle{
public:
    Particle( b2World* const world, ci::Vec2f pos );
    void		display();
	bool		done();
	b2Body      *mBody;
    
private:
    
    b2World     *mWorld;
    float       mRadius;
    
    void		makeBody( ci::Vec2f pos, float r );
    void		killBody();
};