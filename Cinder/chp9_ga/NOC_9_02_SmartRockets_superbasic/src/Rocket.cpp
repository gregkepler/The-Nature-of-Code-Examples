//
//  Rocket.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "Rocket.h"
#include "cinder/CinderMath.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Rocket::Rocket( Vec2f l, DNA* const dna, Vec2f* const target )
{
	mGeneCounter = 0;
	mHitTarget = false;
	mAcceleration = Vec2f::zero();
    mVelocity = Vec2f::zero();
    mLocation = l;
    r = 4;
    mDna = dna;
	mTarget = target;
}

Rocket::~Rocket()
{
	
}

// Fitness function
// fitness = one divided by distance squared
void Rocket::fitness()
{
	float d = mLocation.distance( *mTarget );
	mFitness = pow( 1.0f / d, 2.0f );
	
}

// Run in relation to all the obstacles
// If I'm stuck, don't bother updating or checking for intersection
void Rocket::run()
{
    checkTarget(); // Check to see if we've reached the target
    if( !mHitTarget )
	{
		applyForce( mDna->mGenes[mGeneCounter] );
		mGeneCounter = ( mGeneCounter + 1 ) % mDna->mGenes.size();
		update();
    }
    display();
}

// Did I make it to the target?
void Rocket::checkTarget()
{
    float d = mLocation.distance( *mTarget );
    if( d < 12 )
	{
		mHitTarget = true;
    }
}

void Rocket::applyForce( Vec2f f )
{
    mAcceleration += f;
}

void Rocket::update()
{
    mVelocity += mAcceleration;
    mLocation += mVelocity;
    mAcceleration *= 0;
}

void Rocket::display()
{
	float theta = toDegrees( atan2( mVelocity.y, mVelocity.x ) ) + 90;	// there is no heading2d function in cinder
	
	gl::pushMatrices();
	gl::translate( mLocation );
	gl::rotate( theta );
	
	// Thrusters
	gl::color( Color::black() );
	gl::drawSolidRect( Rectf( -r/2, r*2, r/2, r ) );
	gl::drawStrokedRect( Rectf( -r/2, r*2, r/2, r ) );
	gl::drawSolidRect( Rectf( r/2, r*2, r/2, r ) );
	gl::drawSolidRect( Rectf( r/2, r*2, r/2, r ) );
		
	// Rocket Body
	gl::color( Color8u::gray( 175 ) );
	gl::begin( GL_TRIANGLES );
	gl::vertex( Vec2f( 0.0, -r*2 ) );
	gl::vertex( Vec2f( -r, r*2 ) );
	gl::vertex( Vec2f( r, r*2 ) );
	gl::end();
	
	gl::color( Color::black()  );
	gl::begin( GL_LINE_LOOP );
	gl::vertex( Vec2f( 0.0, -r*2 ) );
	gl::vertex( Vec2f( -r, r*2 ) );
	gl::vertex( Vec2f( r, r*2 ) );
	gl::end();
	gl::popMatrices();
}

DNA* Rocket::getDNA()
{
	return mDna;
}

float Rocket::getFitness()
{
	return mFitness;
}