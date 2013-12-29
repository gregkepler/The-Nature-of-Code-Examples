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

Vehicle::Vehicle( Vec2f loc, float ms, float mf )
{
	mAcceleration = Vec2f( 0.0, 0.0 );
	mVelocity = Vec2f( 3.0, -2.0 );
	mVelocity *= 5.0;
	mLocation = loc;
    r = 6.0;
    mMaxSpeed = ms;
    mMaxForce = mf;
	mBoundaryWidth = 25.0;
}

void Vehicle::run() {
    update();
	borders();
    display();
}

// Implementing Reynolds' flow field following algorithm
// http://www.red3d.com/cwr/steer/FlowFollow.html
void Vehicle::follow( FlowField* const flow )
{
    // What is the vector at that spot in the flow field?
    Vec2f desired = flow->lookup( mLocation );
    // Scale it up by maxspeed
    desired *= mMaxSpeed;
    // Steering is desired minus velocity
    Vec2f steer = desired - mVelocity;
    steer.limit( mMaxForce );  // Limit to maximum steering force
    applyForce( steer );
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

void Vehicle::boundaries()
{	
    Vec2f desired = Vec2f::zero();
	
    if( mLocation.x < mBoundaryWidth ) {
		desired = Vec2f( mMaxSpeed, mVelocity.y );
    }
    else if( mLocation.x > getWindowWidth() - mBoundaryWidth ) {
		desired = Vec2f( -mMaxSpeed, mVelocity.y );
    }
	
    if( mLocation.y < mBoundaryWidth ) {
		desired = Vec2f( mVelocity.x, mMaxSpeed );
    }
    else if( mLocation.y > getWindowHeight() - mBoundaryWidth ) {
		desired = Vec2f( mVelocity.x, -mMaxSpeed );
    }
	
    if ( desired != Vec2f::zero() ) {
		desired.normalize();
		desired *= mMaxSpeed;
		Vec2f steer = desired - mVelocity;
		steer.limit( mMaxForce );
		applyForce(steer);
    }
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
	int width = getWindowWidth();
	int height = getWindowHeight();
    if( mLocation.x < -r ) mLocation.x = width + r;
    if( mLocation.y < -r ) mLocation.y = height + r;
    if( mLocation.x > width + r ) mLocation.x = -r;
    if( mLocation.y > height + r ) mLocation.y = -r;
}