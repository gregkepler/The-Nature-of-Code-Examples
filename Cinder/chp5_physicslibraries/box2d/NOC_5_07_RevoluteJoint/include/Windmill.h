//
//  Windmill.h
//  NOC_5_07_RevoluteJoint
//
//  Created by Greg Kepler on 12/3/13.
//
//

#include "cinder/app/AppNative.h"
#include "Box.h"
#include <Box2D/Box2D.h>

class Windmill{
public:
	Windmill( b2World* const world, ci::Vec2f pos );
	void	toggleMotor();
	bool	motorOn();
	void	display();
	
private:
	b2World				*mWorld;
	Box					*box1, *box2;
	b2RevoluteJoint		*joint;
	//b2Body				*m_bodyA, *m_bodyB;
};