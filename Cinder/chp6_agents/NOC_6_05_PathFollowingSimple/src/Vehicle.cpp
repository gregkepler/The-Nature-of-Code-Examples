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

void Vehicle::run( bool debug ) {
	mDebug = debug;
    update();
    display();
}

// This function implements Craig Reynolds' path following algorithm
// http://www.red3d.com/cwr/steer/PathFollow.html
void Vehicle::follow( Path* const p )
{
	// Predict location 50 (arbitrary choice) frames ahead
	Vec2f predict = Vec2f( mVelocity );
    predict.normalize();
    predict *= 50;
    Vec2f predictLoc = mLocation + predict;
	
    // Look at the line segment
    Vec2f a = p->mStart;
    Vec2f b = p->mEnd;
	
    // Get the normal point to that line
    Vec2f normalPoint = getNormalPoint(predictLoc, a, b);
	
    // Find target point a little further ahead of normal
    Vec2f dir = b - a;
    dir.normalize();
    dir *= 10;  // This could be based on velocity instead of just an arbitrary 10 pixels
    Vec2f target = normalPoint + dir;
	
    // How far away are we from the path?
    float distance = predictLoc.distance( normalPoint );
    // Only if the distance is greater than the path's radius do we bother to steer
    if (distance > p->mRadius) {
		seek(target);
    }
	
	// Draw the debugging stuff
    if( mDebug )
	{
		gl::color( Color::black() );
		gl::drawLine( mLocation, predictLoc );
		gl::drawSolidEllipse( predictLoc, 4.0, 4.0 );
		
		/*// Draw normal location
		 fill(0);
		 stroke(0);
		 line(predictLoc.x, predictLoc.y, normalPoint.x, normalPoint.y);
		 ellipse(normalPoint.x, normalPoint.y, 4, 4);
		 stroke(0);
		 if (distance > p.radius) fill(255, 0, 0);
		 noStroke();
		 ellipse(target.x+dir.x, target.y+dir.y, 8, 8);*/
    }
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
void Vehicle::borders( Path* const p )
{
/*	int width = getWindowWidth();
	int height = getWindowHeight();
    if( mLocation.x < -r ) mLocation.x = width + r;
    if( mLocation.y < -r ) mLocation.y = height + r;
    if( mLocation.x > width + r ) mLocation.x = -r;
    if( mLocation.y > height + r ) mLocation.y = -r;*/
	
	if( mLocation.x > p->mEnd.x + r ) {
		mLocation.x = p->mStart.x - r;
		mLocation.y = p->mStart.y + ( mLocation.y - p->mEnd.y );
    }
}