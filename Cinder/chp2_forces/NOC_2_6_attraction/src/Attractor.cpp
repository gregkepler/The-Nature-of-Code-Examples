//
//  Attractor.cpp
//  A class for a draggable attractive body in our world
//  NOC_2_6_attraction
//
//  Created by Greg Kepler on 11/22/12.
//
//

#include "Attractor.h"

using namespace ci;
using namespace ci::app;
using namespace std;

vec2 Attractor::attract( const Mover &m )
{
	vec2 force = mLocation - m.mLocation;						// Calculate direction of force
    float d = length( force );									// Distance between objects
    d = constrain( d, 5.0f, 25.0f );							// Limiting the distance to eliminate "extreme" results for very close or very far objects
	force = normalize( force );											// Normalize vector (distance doesn't matter here, we just want this vector for direction)
    float strength = ( mGravity * mMass * m.mMass ) / ( d * d );	// Calculate gravitional force magnitude
    force *= strength;											// Get force vector --> magnitude * direction
    return force;
}

// Method to display
void Attractor::display()
{
	gl::lineWidth( 4.0f );
	
    if( mDragging )
		gl::color( Color8u::gray( 50 ) );
    else if( mRollover )
		gl::color( Color8u::gray( 100 ) );
	else
		gl::color( ColorA8u::gray( 175, 200 ) );
	
	gl::drawSolidEllipse( mLocation, mMass, mMass );
	gl::color( Color::black() );
	gl::drawStrokedEllipse( mLocation, mMass, mMass );
}

// The methods below are for mouse interaction
void Attractor::clicked( vec2 mouseLoc )
{
	float d = distance( mLocation, mouseLoc );
    if( d < mMass ) {
		mDragging = true;
		mDragOffset = mLocation - mouseLoc;
    }
}

void Attractor::hover( vec2 mouseLoc )
{
    //float d = dist(mx,my,location.x,location.y);
	float d = distance( mLocation, mouseLoc );
    if( d < mMass ){
		mRollover = true;
    }
    else {
		mRollover = false;
    }
}

void Attractor::stopDragging() {
    mDragging = false;
}

void Attractor::drag( vec2 mouseLoc ) {
    if( mDragging ) {
		mLocation  = mouseLoc + mDragOffset;
    }
}
