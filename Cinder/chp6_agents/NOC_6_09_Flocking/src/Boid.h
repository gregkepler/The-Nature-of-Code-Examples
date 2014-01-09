//
//  Boid.h
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"

class Boid {
	ci::Vec2f		mVelocity;
	ci::Vec2f		mAcceleration;
	float			r;
	float			mMaxForce;    // Maximum steering force
	float			mMaxSpeed;    // Maximum speed
	float			mBoundaryWidth;
	
public:
	Boid( ci::Vec2f loc );
	
	ci::Vec2f		mLocation;
	
	void		run( std::vector<Boid*>* const boids );
	void		flock( std::vector<Boid*>* const boids );
	void		update();
	void		applyBehaviors( std::vector<Boid*>* const boids, ci::Vec2f mousePos );
	ci::Vec2f	seek( ci::Vec2f target );
	ci::Vec2f	separate( std::vector<Boid*>* const boids );
	ci::Vec2f	align( std::vector<Boid*>* const boids );
	ci::Vec2f	cohesion( std::vector<Boid*>* const boids );
	void		applyForce( ci::Vec2f force );
	void		render();
	void		borders();
};