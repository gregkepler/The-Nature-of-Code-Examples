//
//  Particle.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Particle::Particle(){
	mRadius = 32.0;
}

void Particle::display()
{
	gl::color( Color8u::gray( 127 ) );
	gl::drawSolidEllipse( mPos, mRadius, mRadius );
	
	gl::color( Color::black() );
	gl::drawSolidEllipse( mPos, mRadius, mRadius );
}


