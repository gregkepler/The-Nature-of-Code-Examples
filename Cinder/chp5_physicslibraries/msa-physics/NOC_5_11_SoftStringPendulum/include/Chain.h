//
//  Chain.h
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "MSAPhysics2D.h"
#include "Particle.h"

class Chain {
public:
	Chain( msa::physics::World2D* const world, float length, int numPts, float rad, float stren );
	void contains( ci::Vec2f pos );
	void release();
	void updateTail( ci::Vec2f pos );
	void display();
	
	
	msa::physics::World2D		*mWorld;
	
	// Chain properties
	float				mTotalLength;	// How long
	int					mNumPoints;      // How many points
	float				mStrength;		// Strength of springs
	float				mRadius;			// Radius of ball at tail
	
	// This list is redundant since we can ask for physics.particles, but in case we have many of these
	// it's a convenient to keep track of our own list
	vector<Particle*>	mParticles;
	
	// Let's keep an extra reference to the tail particle
	// This is just the last particle in the ArrayList
	Particle*			mTail;
	
	// Some variables for mouse dragging
	ci::Vec2f			mOffset;
	bool				mDragged;
};