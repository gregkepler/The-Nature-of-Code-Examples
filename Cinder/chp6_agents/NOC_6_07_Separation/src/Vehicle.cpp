//
//  Vehicle.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "Vehicle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Vehicle::Vehicle( Vec2f loc )
{
	mLocation = loc;
    r = 12.0;
    mMaxSpeed = 3.0;
    mMaxForce = 0.2;
	mAcceleration = Vec2f::zero();
	mVelocity = Vec2f( mMaxSpeed, 0.0 );
}

// Main "run" function
void Vehicle::run( bool debug ) {
	mDebug = debug;
    update();
    display();
}



// A function to get the normal point from a point (p) to a line segment (a-b)
// This function could be optimized to make fewer new Vector objects
Vec2f Vehicle::getNormalPoint( Vec2f p, Vec2f a, Vec2f b)
{
    // Vector from a to p
    Vec2f ap = p - a;
    // Vector from a to b
    Vec2f ab = b - a;
    ab.normalize(); // Normalize the line
    // Project vector "diff" onto line by using the dot product
    ab *= ap.dot(ab);
    Vec2f normalPoint = a + ab;
    return normalPoint;
}

// Method to update location
void Vehicle::update()
{
    // Update velocity
    mVelocity += mAcceleration;
    // Limit speed
    mVelocity.limit( mMaxSpeed );
    mLocation += mVelocity;
    // Reset accelerationelertion to 0 each cycle
	mAcceleration = Vec2f::zero();
}

void Vehicle::applyForce( Vec2f force )
{
    // We could add mass here if we want A = F / M
    mAcceleration += force;
}

// A method that calculates and applies a steering force towards a target
// STEER = DESIRED MINUS VELOCITY
void Vehicle::seek( Vec2f target )
{
    Vec2f desired = target - mLocation;  // A vector pointing from the location to the target
	
    // If the magnitude of desired equals 0, skip out of here
    // (We could optimize this to check if x and y are 0 to avoid mag() square root
    if( desired.length() == 0 ) return;
	
    // Normalize desired and scale to maximum speed
    desired.normalize();
    desired *= mMaxSpeed;
    // Steering = Desired minus Velocity
    Vec2f steer = desired - mVelocity;
    steer.limit( mMaxForce );  // Limit to maximum steering force
	
	applyForce( steer );
}

void Vehicle::display()
{
    // Draw a triangle rotated in the direction of velocity
	float theta = toDegrees( atan2( mVelocity.y, mVelocity.x ) ) + 90;	// there is no heading2d function in cinder

	glPushMatrix();
	gl::translate( mLocation );
	gl::rotate( theta );
	
	gl::color( Color8u::gray( 127 ) );
	gl::begin( GL_TRIANGLE_STRIP );
	gl::vertex( Vec2f( 0.0, -r * 2.0 ) );
	gl::vertex( Vec2f( -r, r * 2.0 ) );
	gl::vertex( Vec2f( r, r * 2.0 ) );
	gl::end();

	gl::color( Color8u::black() );
	gl::begin( GL_LINE_LOOP );
	gl::vertex( Vec2f( 0.0, -r * 2.0 ) );
	gl::vertex( Vec2f( -r, r * 2.0 ) );
	gl::vertex( Vec2f( r, r * 2.0 ) );
	gl::end();
    glPopMatrix();
}

// Wraparound
void Vehicle::borders()
{
	/*if( mLocation.x > p->mEnd.x + r )
	{
		mLocation.x = p->mStart.x - r;
		mLocation.y = p->mStart.y + ( mLocation.y - p->mEnd.y );
    }*/
}