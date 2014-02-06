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

Rocket::Rocket( Vec2f l, DNA* const dna, Obstacle* const target )
{
	mAcceleration = Vec2f::zero();
    mVelocity = Vec2f::zero();
    mLocation = l;
	r = 4;
    mDna = dna;
	mTarget = target;
	mFinishTime = 0;          // We're going to count how long it takes to reach target
    mRecordDist = 10000;      // Some high number that will be beat instantly
	mHitObstacle = 0;
	mHitTarget = 0;
	mGeneCounter = 0;
}

Rocket::~Rocket()
{
	
}

// FITNESS FUNCTION
// distance = distance from target
// finish = what order did i finish (first, second, etc. . .)
// f(distance,finish) =   (1.0f / finish^1.5) * (1.0f / distance^6);
// a lower finish is rewarded (exponentially) and/or shorter distance to target (exponetially)
void Rocket::fitness()
{
//	float d = mLocation.distance( *mTarget );
//	mFitness = pow( 1.0f / d, 2.0f );
	
	
	if( mRecordDist < 1 ) mRecordDist = 1;
	
    // Reward finishing faster and getting close
    mFitness = ( 1.0 / ( mFinishTime * mRecordDist ) );
	
    // Make the function exponential
    mFitness = pow( mFitness, 4 );
	
    if( mHitObstacle ) mFitness *= 0.1; // lose 90% of fitness hitting an obstacle
    if( mHitTarget ) mFitness *= 2.0; // twice the fitness for finishing!
	
}

// Run in relation to all the obstacles
// If I'm stuck, don't bother updating or checking for intersection
void Rocket::run( vector<Obstacle*> const os )
{
    if( !mHitObstacle && !mHitTarget )
	{
		applyForce( mDna->mGenes[mGeneCounter] );
		mGeneCounter = ( mGeneCounter + 1 ) % mDna->mGenes.size();
		update();
		// If I hit an edge or an obstacle
		obstacles( os );
    }
	
    // Draw me!
    if( !mHitObstacle )
	{
		display();
    }
}

// Did I make it to the target?
void Rocket::checkTarget()
{
    float d = mLocation.distance( mTarget->mLocation );
	if( d < mRecordDist ) mRecordDist = d;
	
    if( mTarget->contains( mLocation ) && !mHitTarget )
	{
		mHitTarget = true;
    }
    else if( !mHitTarget )
	{
		mFinishTime++;
    }
}

// Did I hit an obstacle?
void Rocket::obstacles( vector<Obstacle*> const os )
{
    for( Obstacle *obs: os ) {
		if( obs->contains( mLocation ) ) {
			mHitObstacle = true;
		}
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

bool Rocket::stopped()
{
    return mHitObstacle;
}