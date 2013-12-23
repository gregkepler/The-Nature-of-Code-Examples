//
//  Chain.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "MSAPhysics2D.h"
#include "MSAPhysicsSpring.h"
#include "Chain.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Chain::Chain( msa::physics::World2D* const world, float length, int numPts, float rad, float stren )
{
	mWorld = world;
	
    mTotalLength = length;
    mNumPoints = numPts;
    mRadius = rad;
    mStrength = stren;
	mOffset = Vec2f::zero();
	mDragged = false;
	
    float len = mTotalLength / mNumPoints;
	
    // Here is the real work, go through and add particles to the chain itself
    for( int i = 0; i < mNumPoints; i++ )
	{
		// Make a new particle with an initial starting location
		Particle *particle = new Particle( Vec2f( getWindowWidth() / 2, i * len ) );
		particle->setRadius( 0.0 ); // set to 0.0 or else the default is 15.0.
		
		// Redundancy, we put the particles both in physics and in our own ArrayList
		mWorld->addParticle( particle );
		mParticles.push_back( particle );
		
		// Connect the particles with a Spring (except for the head)
		if (i != 0) {
			Particle *previous = mParticles[i-1];
			// Add the spring to the physics world
			mWorld->makeSpring( particle, previous, mStrength, len );
		}
    }
	
	// Keep the top fixed
    Particle *head = mParticles[0];
	head->makeFixed();

    // Store reference to the tail
    mTail = mParticles[mNumPoints-1];
    mTail->setRadius( mRadius );
}

// Check if a point is within the ball at the end of the chain
// If so, set dragged = true;
void Chain::contains( Vec2f pos )
{
//    float d = dist(x,y,tail.x,tail.y);
	float d = pos.distance( mTail->getPosition() );
    if( d < mRadius ) {
		mOffset.x = mTail->getPosition().x - pos.x;
		mOffset.y = mTail->getPosition().y - pos.y;
		mTail->makeFixed();
		mDragged = true;
    }
}

// Release the ball
void Chain::release()
{
	mTail->makeFree();
    mDragged = false;
}

// Update tail location if being dragged
void Chain::updateTail( Vec2f pos )
{
    if( mDragged )
	{
		mTail->moveTo( Vec2f( pos.x + mOffset.x, pos.y + mOffset.y ) );
    }
}

// Draw the chain
void Chain::display()
{
    // Draw line connecting all points
	gl::color( Color::black() );
	gl::lineWidth( 2.0 );
	for( vector<Particle*>::iterator p = mParticles.begin() + 1; p != mParticles.end(); ++p )
	{
		gl::drawLine( (*(p-1))->getPosition(), (*p)->getPosition() );
	}
	mTail->display();
}