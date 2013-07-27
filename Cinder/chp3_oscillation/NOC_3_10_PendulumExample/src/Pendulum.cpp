//
//  Pendulum.cpp
//  NOC_3_10_PendulumExample
//
//  Created by Greg Kepler on 1/19/13.
//
//

#include "cinder/app/AppBasic.h"
#include "Pendulum.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Pendulum::Pendulum()
{
	
}

// This constructor could be improved to allow a greater variety of pendulums
Pendulum::Pendulum( ci::Vec2f origin, float r )
{
	// Fill all variables
	mOrigin = origin;
    mLocation = Vec2f(0, 0);
    mRadius = r;
    mAngle = M_PI/4;
	
    mAVelocity = 0.0;
    mAAcceleration = 0.0;
    mDamping = 0.995;		// Arbitrary damping
    mBallr = 24.0;			// Arbitrary ball radius
}

// Broken down to update, drag, and draw functions called from the main class
/*
void Pendulum::go() {
    update();
    drag(); 
    display();
}*/

// Function to update location
void Pendulum::update()
{
    // As long as we aren't dragging the pendulum, let it swing!
    if ( !mDragging ) {
		float gravity = 0.4f;											// Arbitrary constant
		mAAcceleration = ( -1 * gravity / mRadius ) * sin( mAngle );	// Calculate acceleration (see: http://www.myphysicslab.com/pendulum1.html)
		mAVelocity += mAAcceleration;									// Increment velocity
		mAVelocity *= mDamping;											// Arbitrary damping
		mAngle += mAVelocity;											// Increment angle
    }
}



// The methods below are for mouse interaction

// This checks to see if we clicked on the pendulum ball
void Pendulum::clicked( ci::Vec2f mousePos )
{
	float d = mousePos.distance( mLocation );
	
    if (d < mBallr)
	{
		mDragging = true;
    }
}

// This tells us we are not longer clicking on the ball
void Pendulum::stopDragging()
{
    mAVelocity = 0;			// No velocity once you let go
    mDragging = false;
}

void Pendulum::drag( Vec2f mousePos )
{
    // If we are draging the ball, we calculate the angle between the
    // pendulum origin and mouse location
    // we assign that angle to the pendulum
    if ( mDragging ) {
		Vec2f diff = mOrigin - mousePos;									// Difference between 2 points
		console()<< diff << endl;
		mAngle = atan2( -1 * diff.y, diff.x ) - toRadians( 90.0f );			// Angle relative to vertical axis
    }
}




void Pendulum::draw()
{
    mLocation = Vec2f( mRadius * sin( mAngle ), mRadius * cos( mAngle ) );	// Polar to cartesian conversion
    mLocation += mOrigin;													// Make sure the location is relative to the pendulum's origin
	
	gl::color( Color::black() );
	glLineWidth( 2.0 );
    
	// Draw the arm
	gl::drawLine( mOrigin, mLocation );
	
    if (mDragging) gl::color( Color8u::black() );
	else gl::color( Color8u::gray( 175 ) );
    
	// Draw the ball
	gl::drawSolidEllipse( mLocation, mBallr, mBallr );
	
	gl::color( Color::black() );
	gl::drawStrokedEllipse( mLocation, mBallr, mBallr );
}


