//
//  Vehicle.cpp
//

#include "cinder/app/AppNative.h"
#include "cinder/CinderMath.h"
#include "Vehicle.h"


using namespace ci;
using namespace ci::app;
using namespace std;

Vehicle::Vehicle( int n, Vec2f loc, Vec2f desired )
{
	mBrain = new Perceptron( n, 0.001 );
	mAcceleration = Vec2f( 0.0, 0.0 );
	mVelocity = Vec2f( 0.0, 0.0 );
	mLocation = loc;
    r = 3.0;
    mMaxSpeed = 4.0;
    mMaxForce = 0.1;
	mDesired = desired;
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
	
	mLocation.x = constrain( mLocation.x, 0.0f, float( getWindowWidth() ) );
    mLocation.y = constrain( mLocation.y, 0.0f, float( getWindowHeight() ) );
}

void Vehicle::applyForce( Vec2f force )
{
    // We could add mass here if we want A = F / M
    mAcceleration += force;
}

// A method that calculates a steering force towards a target
// STEER = DESIRED MINUS VELOCITY
void Vehicle::steer( vector<Vec2f> targets )
{
	// Make an array of forces
    vector<Vec2f> forces;
	forces.resize( targets.size() );
    
    // Steer towards all targets
    for( int i = 0; i < forces.size(); i++) {
		forces[i] = seek( targets[i] );
    }
    
    // That array of forces is the input to the brain
    Vec2f result = mBrain->feedforward( forces );
    
    // Use the result to steer the vehicle
    applyForce(result);
    
    // Train the brain according to the error
    Vec2f error = mDesired - mLocation;
    mBrain->train( forces, error );
}

// A method that calculates a steering force towards a target
// STEER = DESIRED MINUS VELOCITY
Vec2f Vehicle::seek( Vec2f target )
{
    Vec2f desired = target - mLocation;  // A vector pointing from the location to the target
	
    // Normalize desired and scale to maximum speed
	desired.normalize();
	desired *= mMaxSpeed;
	
    // Steering = Desired minus velocity
    Vec2f steer = desired - mVelocity;
    steer.limit( mMaxForce );  // Limit to maximum steering force
    
	return steer;
}

void Vehicle::display() {
    // Draw a triangle rotated in the direction of velocity
	float theta = toDegrees( atan2( mVelocity.y, mVelocity.x ) ) + 90;	// there is no heading2d function in cinder
	
	glPushMatrix();
	gl::translate( mLocation );
	gl::rotate( theta );
	
	gl::color( Color8u::gray( 175 ) );
	gl::begin( GL_TRIANGLE_STRIP );
	gl::vertex( Vec2f( 0.0, -r * 2.0 ) );
	gl::vertex( Vec2f( -r, r * 2.0 ) );
	gl::vertex( Vec2f( r, r * 2.0 ) );
	gl::end();
	
	gl::lineWidth( 1.0 );
	gl::color( Color8u::black() );
	gl::begin( GL_LINE_LOOP );
	gl::vertex( Vec2f( 0.0, -r * 2.0 ) );
	gl::vertex( Vec2f( -r, r * 2.0 ) );
	gl::vertex( Vec2f( r, r * 2.0 ) );
	gl::end();
    glPopMatrix();
}