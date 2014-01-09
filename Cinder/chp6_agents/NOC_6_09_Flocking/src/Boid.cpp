//
//  Boid.cpp
//
//  Created by Greg Kepler
//
//

#include "Boid.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Boid::Boid( Vec2f loc )
{
	mAcceleration = Vec2f::zero();
	mVelocity = Vec2f( randFloat( -1.0, 1.0 ), randFloat( -1.0, 1.0 ) );
	mLocation = loc;
    r = 3.0;
    mMaxSpeed = 3.0;
    mMaxForce = 0.05;
}

void Boid::run( vector<Boid*>* const boids )
{
	flock( boids );
	update();
	borders();
	render();
}

void Boid::applyForce( Vec2f force )
{
    // We could add mass here if we want A = F / M
    mAcceleration += force;
}

// We accumulate a new acceleration each time based on three rules
void Boid::flock( vector<Boid*>* const boids )
{
	Vec2f sep = separate( boids );   // Separation
    Vec2f ali = align( boids );      // Alignment
    Vec2f coh = cohesion( boids);   // Cohesion
    // Arbitrarily weight these forces
    sep *= 1.5;
    ali *- 1.0;
    coh *= 1.0;
    // Add the force vectors to acceleration
    applyForce(sep);
    applyForce(ali);
    applyForce(coh);
}



void Boid::applyBehaviors( std::vector<Boid*>* const Boids, Vec2f mousePos )
{
	Vec2f separateForce = separate( Boids );
	Vec2f seekForce = seek( mousePos );
	separateForce *= 2;
	seekForce *= 1;
	applyForce(separateForce);
	applyForce(seekForce);
}

// A method that calculates a steering force towards a target
// STEER = DESIRED MINUS VELOCITY
Vec2f Boid::seek( Vec2f target )
{
    Vec2f desired = target - mLocation;  // A vector pointing from the location to the target
    // Scale to maximum speed
	// set mag are these 2 functions combined into 1 function
	desired.normalize();
	desired *= mMaxSpeed;
	
    // Steering = Desired minus velocity
    Vec2f steer = desired - mVelocity;
    steer.limit( mMaxForce );  // Limit to maximum steering force
    
	return steer;
}

// Wraparound
void Boid::borders()
{
	int width = getWindowWidth();
	int height = getWindowHeight();
    if( mLocation.x < -r ) mLocation.x = width + r;
    if( mLocation.y < -r ) mLocation.y = height + r;
    if( mLocation.x > width + r ) mLocation.x = -r;
    if( mLocation.y > height + r ) mLocation.y = -r;
}

// Separation
// Method checks for nearby Boids and steers away
Vec2f Boid::separate( std::vector<Boid*>* const Boids )
{
	float desiredseparation = 25.0f;
	Vec2f steer = Vec2f::zero();
    int count = 0;
    // For every boid in the system, check if it's too close
    for( Boid *other : *Boids )
	{
		float d = mLocation.distance( other->mLocation );
		// If the distance is greater than 0 and less than an arbitrary amount (0 when you are yourself)
		if( ( d > 0 ) && ( d < desiredseparation ) )
		{
			// Calculate vector pointing away from neighbor
			Vec2f diff = mLocation - other->mLocation;
			diff.normalize();
			diff /= d;			// Weight by distance
			steer += diff;
			count++;            // Keep track of how many
		}
    }
    // Average -- divide by how many
    if( count > 0 )
	{
		steer /= count;
    }
	
	// As long as the vector is greater than 0
	if( steer.length() > 0 )
	{
		// Implement Reynolds: Steering = Desired - Velocity
		steer.normalize();
		steer *= mMaxSpeed;
		steer -= mVelocity;
		steer.limit( mMaxForce );
	}
	
	return steer;
}

// Cohesion
// For the average location (i.e. center) of all nearby boids, calculate steering vector towards that location
Vec2f Boid::cohesion(  std::vector<Boid*>* const Boids )
{
    float neighbordist = 50;
    Vec2f sum = Vec2f::zero();   // Start with empty vector to accumulate all locations
    int count = 0;
    for( Boid *other : *Boids )
	{
		float d = mLocation.distance( other->mLocation );
		if ((d > 0) && (d < neighbordist)) {
			sum += other->mLocation; // Add location
			count++;
		}
    }
    if (count > 0) {
		sum /= count;
		return seek( sum );  // Steer towards the location
    } else {
		return Vec2f::zero();
    }
}

// Alignment
// For every nearby boid in the system, calculate the average velocity
Vec2f Boid::align( std::vector<Boid*>* const Boids )
{
    float neighbordist = 50;
    Vec2f sum = Vec2f::zero();
    int count = 0;
    for( Boid *other : *Boids )
	{
		float d = mLocation.distance( other->mLocation );
		if( (d > 0) && ( d < neighbordist ) )
		{
			sum += other->mVelocity;
			count++;
		}
    }
    if (count > 0)
	{
		sum /= count;
		sum.normalize();
		sum *= mMaxSpeed;
		Vec2f steer = sum - mVelocity;
		steer.limit( mMaxForce );
		return steer;
    } else {
		return Vec2f::zero();
    }
}

// Method to update location
void Boid::update()
{
    // Update velocity
    mVelocity += mAcceleration;
    // Limit speed
    mVelocity.limit( mMaxSpeed );
    mLocation += mVelocity;
    // Reset accelerationelertion to 0 each cycle
	mAcceleration = Vec2f::zero();
}

void Boid::render()
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