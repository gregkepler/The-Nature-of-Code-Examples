//
//  Repeller.cpp
//  NOC_4_07_ParticleSystemForcesRepeller
//
//  Created by Greg Kepler on 11/4/13.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/CinderMath.h"
#include "Repeller.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Repeller::Repeller()
{
	mLocation = Vec2f::zero();
	mGravity = 100.0;
}

Repeller::Repeller( Vec2f location )
{
	mLocation = location;
	mGravity = 100.0;
}

// Calculate a force to push particle away from repeller
Vec2f Repeller::repel( Particle p )
{
	Vec2f dir = mLocation - p.getLocation();	// Calculate direction of force
    float d = dir.length();						// Distance between objects
    dir.normalize();							// Normalize vector (distance doesn't matter here, we just want this vector for direction)
    d = constrain( d, 5.0f, 100.0f );			// Keep distance within a reasonable range/*
    float force = -1 * mGravity / ( d * d );		// Repelling force is inversely proportional to distance
    dir *= force;								// Get force vector --> magnitude * direction*/
    return dir;
}

void Repeller::display()
{
	// solid circle
	gl::color( Color8u::gray( 175 ) );
	gl::drawSolidEllipse( mLocation, 24.0, 24.0 );
	
	// circle stroke
	gl::lineWidth( 2.0 );
	gl::color( Color::black() );
	gl::drawStrokedEllipse( mLocation, 24.0, 24.0 );
}