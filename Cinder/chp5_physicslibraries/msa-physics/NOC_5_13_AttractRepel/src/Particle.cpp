//
//  Particle.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "MSAPhysics2D.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Particle::Particle( Vec2f pos )
{
	mRadius = 8.0;
	moveTo( pos );
}

void Particle::display()
{
	gl::lineWidth( 2.0 );
	gl::color( Color8u::gray( 127 ) );
	gl::drawSolidEllipse( getPosition(), mRadius, mRadius );
	gl::color( Color::black() );
	gl::drawStrokedEllipse( getPosition(), mRadius, mRadius );
}


