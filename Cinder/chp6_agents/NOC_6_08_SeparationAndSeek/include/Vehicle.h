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
	float			mBoundaryWidth;
	
	
public:
	Vehicle( ci::Vec2f loc );
	void		update();
	void		applyBehaviors( std::vector<Vehicle*>* const vehicles, ci::Vec2f mousePos );
	ci::Vec2f	seek( ci::Vec2f target );
	ci::Vec2f	separate( std::vector<Vehicle*>* const vehicles );
	void		applyForce( ci::Vec2f force );
	void		display();
};