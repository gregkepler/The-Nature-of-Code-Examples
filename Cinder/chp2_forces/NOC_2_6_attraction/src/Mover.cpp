//
//  Mover.cpp
//  NOC_2_6_attraction
//
//  Created by Greg Kepler on 11/13/12.
//
//

#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;


void Mover::applyForce( vec2 force )
{
	vec2 f = force / mMass;
	mAcceleration += f;
}

void Mover::update()
{
	mVelocity += mAcceleration;
	mLocation += mVelocity;
	mAcceleration *= 0.0f;
}

void Mover::checkEdges()
{
	float width = getWindowWidth();
	float height = getWindowHeight();
	
	if( mLocation.x > width ) {
		mLocation.x = width;
		mVelocity.x *= -1.0f;
    } else if( mLocation.x < 0.0f ) {
		mVelocity.x *= -1.0f;
		mLocation.x = 0.0f;
    }
	
    if( mLocation.y > height ) {
		mVelocity.y *= -1.0;
		mLocation.y = height;
    }
}

void Mover::display()
{
	gl::color( ColorA::gray( 0.0f, 0.5f ) );
	gl::drawSolidEllipse( mLocation, mMass * 8.0f, mMass * 8.0f );
	
	gl::lineWidth( 2.0f );
	gl::color( Color::black() );
	gl::drawStrokedEllipse( mLocation, mMass * 8.0f, mMass * 8.0f );
}

void Mover::reset( ci::vec2 loc )
{
	mLocation = loc;
}
