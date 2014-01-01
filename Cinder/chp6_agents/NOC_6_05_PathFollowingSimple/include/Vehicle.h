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
	
	void			borders();
	
public:
	Vehicle();
	Vehicle( ci::Vec2f loc, float ms, float mf );
	void	update();
	void	applyForce( ci::Vec2f force );
	void	boundaries();
	void	run();
	void	display();
//	void	follow( FlowField* const flowField );
};