//
//  Vehicle.h
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"

class Vehicle {
	ci::Vec2f		mLocation;
	ci::Vec2f		mVelocity;
	ci::Vec2f		mAcceleration;
	float			r;
	float			mMaxForce;    // Maximum steering force
	float			mMaxSpeed;    // Maximum speed
	
public:
	Vehicle( ci::Vec2f loc );
	void	update();
	void	applyForce( ci::Vec2f force );
	void	arrive( ci::Vec2f target );
	void	display();
};