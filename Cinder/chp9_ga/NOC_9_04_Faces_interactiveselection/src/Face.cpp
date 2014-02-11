//
//  Face.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "Face.h"
#include "cinder/CinderMath.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Face::Face( Vec2f l, DNA* const dna )
{
	mGeneCounter = 0;
	mHitTarget = false;
	mAcceleration = Vec2f::zero();
    mVelocity = Vec2f::zero();
    mLocation = l;
    r = 4;
    mDna = dna;
}

Face::~Face()
{
	
}

// Fitness function
// fitness = one divided by distance squared
void Face::fitness()
{
//	float d = mLocation.distance( *mTarget );
//	mFitness = pow( 1.0f / d, 2.0f );
	
}

// Run in relation to all the obstacles
// If I'm stuck, don't bother updating or checking for intersection
void Face::run()
{

    if( !mHitTarget )
	{
		applyForce( mDna->mGenes[mGeneCounter] );
		mGeneCounter = ( mGeneCounter + 1 ) % mDna->mGenes.size();
		update();
    }
    display();
}


void Face::applyForce( Vec2f f )
{
    mAcceleration += f;
}

void Face::update()
{
    mVelocity += mAcceleration;
    mLocation += mVelocity;
    mAcceleration *= 0;
}

void Face::display()
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
		
	// Face Body
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

DNA* Face::getDNA()
{
	return mDna;
}

float Face::getFitness()
{
	return mFitness;
}