//
//  Vehicle.h
//
//  Created by Greg Kepler
//

#include "cinder/app/AppNative.h"
#include "Perceptron.h"

class Vehicle {

	Perceptron		*mBrain;			// Vehicle now has a brain!
	ci::Vec2f		mLocation;
	ci::Vec2f		mVelocity;
	ci::Vec2f		mAcceleration;
	float			r;
	float			mMaxForce;			// Maximum steering force
	float			mMaxSpeed;			// Maximum speed
	ci::Vec2f		mDesired;
	
public:
	Vehicle( int n, ci::Vec2f loc, ci::Vec2f desired );
	void		update();
	void		applyForce( ci::Vec2f force );
	void		steer( std::vector<ci::Vec2f> targets );
	ci::Vec2f	seek( ci::Vec2f target );
	void		display();
};