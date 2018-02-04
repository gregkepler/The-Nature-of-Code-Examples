//
//  Mover.cpp
//  NOC_2_7_attraction_many
//
//  Created by Greg Kepler on 11/13/12.
//
//

#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Mover::Mover( float m, float x , float y ):
	mAngle( 0 ), mAAcceleration( 0 ), mAVelocity( 0 )
{
	mMass = m;
	mLocation = vec2( x, y );
	mVelocity = vec2( randFloat( -1.0f, 1.0f ), randFloat( -1.0f, 1.0f ) );
	mAcceleration = vec2();
}

void Mover::applyForce( vec2 force )
{
	vec2 f = force / mMass;
	mAcceleration += f;
}

void Mover::update()
{
	mVelocity += mAcceleration;
	mLocation += mVelocity;
	
	mAAcceleration = mAcceleration.x / 10.0f;
	mAVelocity += mAAcceleration;
	mAVelocity = constrain( mAVelocity, -0.1f, 0.1f );
	mAngle += mAVelocity;
	
	mAcceleration *= 0;
}

void Mover::display()
{
	float w = mMass * 16.0;
	Rectf drawRect = Rectf( -w/2.0f, -w/2.0f, w/2.0f, w/2.0f );
	
	gl::ScopedMatrices scpMtrx;
	gl::translate( mLocation );
	gl::rotate( mAngle );
	
	gl::color( ColorA8u::gray( 175, 200 ) );
	gl::drawSolidRect( drawRect );
	
	gl::color( Color::black() );
	gl::drawStrokedRect( drawRect );
}
