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
	mLocation = loc;
    r = 4.0;
    mMaxSpeed = ms;
    mMaxForce = mf;
	mAcceleration = Vec2f::zero();
	mVelocity = Vec2f( mMaxSpeed, 0.0 );
}

// Main "run" function
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
	
	// Now we must find the normal to the path from the predicted location
    // We look at the normal for each line segment and pick out the closest one
	
	Vec2f normal;
    Vec2f target;
    float worldRecord = 1000000.0;  // Start with a very high record distance that can easily be beaten
	
    // Look at the line segment
    Vec2f a = p->mStart;
    Vec2f b = p->mEnd;
	
	// Loop through all points of the path
    for( int i = 0; i < p->mPoints.size()-1; i++ )
	{
		
		// Look at a line segment
		Vec2f a = p->mPoints[i];
		Vec2f b = p->mPoints[i+1];
		
		// Get the normal point to that line
		Vec2f normalPoint = getNormalPoint( predictLoc, a, b );
		// This only works because we know our path goes from left to right
		// We could have a more sophisticated test to tell if the point is in the line segment or not
		if (normalPoint.x < a.x || normalPoint.x > b.x) {
			// This is something of a hacky solution, but if it's not within the line segment
			// consider the normal to just be the end of the line segment (point b)
			normalPoint = Vec2f( b );
		}
		
		// How far away are we from the path?
		float distance = predictLoc.distance( normalPoint );
		// Did we beat the record and find the closest line segment?
		if (distance < worldRecord) {
			worldRecord = distance;
			// If so the target we want to steer towards is the normal
			normal = normalPoint;
			
			// Look at the direction of the line segment so we can seek a little bit ahead of the normal
			Vec2f dir = b - a;
			dir.normalize();
			// This is an oversimplification
			// Should be based on distance to path & velocity
			dir *= 10;
			target = Vec2f( normalPoint );
			target += dir;
		}
    }
	
    // Only if the distance is greater than the path's radius do we bother to steer
    if (worldRecord > p->mRadius) {
		seek(target);
    }
	
	// Draw the debugging stuff
    if( mDebug )
	{
		// Draw predicted future location
		gl::color( Color::black() );
		gl::drawLine( mLocation, predictLoc );
		gl::drawSolidEllipse( predictLoc, 2.0, 2.0 );
		
		// Draw normal location
		gl::drawLine( predictLoc, normal );
		gl::drawSolidEllipse( predictLoc, 2.0, 2.0 );
		if( worldRecord > p->mRadius ) gl::color( Color8u( 255, 0, 0 ) );
		gl::drawSolidEllipse( target, 4.0, 4.0);
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
	if( mLocation.x > p->mEnd.x + r )
	{
		mLocation.x = p->mStart.x - r;
		mLocation.y = p->mStart.y + ( mLocation.y - p->mEnd.y );
    }
}