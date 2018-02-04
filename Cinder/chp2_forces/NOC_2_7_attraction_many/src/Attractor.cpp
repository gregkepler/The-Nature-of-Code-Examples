//
//  Attractor.cpp
//  A class for a draggable attractive body in our world
//  NOC_2_7_attraction_many
//
//  Created by Greg Kepler on 11/22/12.
//
//

#include "Attractor.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Attractor::Attractor()
{
	
}

Attractor::Attractor( vec2 loc )
{
	mLocation = loc;
    mMass = 20;
    mGravity = 0.4;
}


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
	gl::lineWidth( 2.0 );
	
	gl::color( Color8u::gray( 127 ) );
	gl::drawSolidEllipse( mLocation, 24, 24 );
	
	gl::color( Color::black() );
	gl::drawStrokedEllipse(mLocation, 24, 24 );
}
