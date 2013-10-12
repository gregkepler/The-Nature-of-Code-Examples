//
//  Bob.cpp instead of Mover
//  NOC_3_11_Spring
//
//  Created by Greg Kepler on 10/7/13.
//
//

#include "cinder/app/AppBasic.h"
#include "Bob.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Bob::Bob()
{
	
}

// Constructor
Bob::Bob( float x, float y )
{
	mLocation = Vec2f( x, y );
    mVelocity = Vec2f( 0, 0 );
    mAcceleration = Vec2f( 0, 0 );
//    dragOffset = Vec2f();
}

void Bob::applyForce( Vec2f force )
{
    force /= mMass;
    mAcceleration += force;
}

// Standard Euler integration
void Bob::update()
{
    mVelocity += mAcceleration;
	mVelocity *= mDamping;
	mLocation += mVelocity;
	mAcceleration = Vec2f( 0, 0 );
}


// The methods below are for mouse interaction

// This checks to see if we clicked on the pendulum ball
void Bob::clicked( ci::Vec2f mousePos )
{
	float d = mousePos.distance( mLocation );
    if (d < mMass) {
		mDragging = true;
		mDragOffset.x = mLocation.x - mousePos.x;
		mDragOffset.y = mLocation.y - mousePos.y;
    }
}

// This tells us we are not longer clicking on the ball
void Bob::stopDragging()
{
    mDragging = false;
}

void Bob::drag( Vec2f mousePos )
{
	if (mDragging) {
		mLocation.x = mousePos.x + mDragOffset.x;
		mLocation.y = mousePos.y + mDragOffset.y;
    }
}



void Bob::display()
{
	Color col = ( mDragging ) ? Color8u::gray(50) : Color8u::gray( 175 );

	gl::color( col );
	gl::drawSolidEllipse( mLocation, mMass, mMass );
	
	gl::color( Color::black() );
	glLineWidth( 2.0 );
	gl::drawStrokedEllipse( mLocation, mMass, mMass );
}


