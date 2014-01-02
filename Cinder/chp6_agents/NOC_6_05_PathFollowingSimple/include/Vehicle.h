//
//  Vehicle.h
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "Path.h"

class Vehicle {
	ci::Vec2f		mLocation;
	ci::Vec2f		mVelocity;
	ci::Vec2f		mAcceleration;
	float			r;
	float			mMaxForce;    // Maximum steering force
	float			mMaxSpeed;    // Maximum speed
	float			mBoundaryWidth;
	bool			mDebug;
	
	ci::Vec2f		getNormalPoint( ci::Vec2f p, ci::Vec2f a, ci::Vec2f b );
	void			seek( ci::Vec2f target );
	
public:
	Vehicle( ci::Vec2f loc, float ms, float mf );
	void	update();
	void	applyForce( ci::Vec2f force );
	void	boundaries();
	void	run( bool debug );
	void	display();
	void	follow( Path* const p );
	void	borders( Path* const p );
};