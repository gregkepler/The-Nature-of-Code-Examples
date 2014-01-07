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

void Vehicle::applyForce( Vec2f force )
{
    // We could add mass here if we want A = F / M
    mAcceleration += force;
}

// Separation
// Method checks for nearby vehicles and steers away
void Vehicle::separate( std::vector<Vehicle*>* const vehicles )
{
	float desiredseparation = r * 2;
    Vec2f sum;
    int count = 0;
    // For every boid in the system, check if it's too close
    for( Vehicle *other : *vehicles )
	{
		float d = mLocation.distance( other->mLocation );
		// If the distance is greater than 0 and less than an arbitrary amount (0 when you are yourself)
		if( ( d > 0 ) && ( d < desiredseparation ) )
		{
			// Calculate vector pointing away from neighbor
			Vec2f diff = mLocation - other->mLocation;
			diff.normalize();
			diff /= d;        // Weight by distance
			sum += diff;
			count++;            // Keep track of how many
		}
    }
    // Average -- divide by how many
    if( count > 0 )
	{
		sum /= count;
		// Our desired vector is the average scaled to maximum speed
		sum.normalize();
		sum *= mMaxSpeed;
		// Implement Reynolds: Steering = Desired - Velocity
		Vec2f steer = sum - mVelocity;
		steer.limit( mMaxForce );
		applyForce(steer);
    }
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

void Vehicle::display()
{
	glPushMatrix();
	gl::translate( mLocation );
	gl::color( Color8u::gray( 175 ) );
	gl::drawSolidEllipse( Vec2f::zero(), r/2, r/2 );
	gl::color( Color::black() );
	gl::drawStrokedEllipse( Vec2f::zero(), r/2, r/2 );
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
