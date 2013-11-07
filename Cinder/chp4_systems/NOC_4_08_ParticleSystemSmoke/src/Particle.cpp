//
//  Particle
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Particle::Particle()
{
	
}

Particle::Particle( ci::Vec2f location, ci::gl::Texture img )
{
	// Fill all variables
	mAcceleration = Vec2f( 0.0, 0.0 );
    mVelocity = Vec2f( randGaussian() * 0.3, ( randGaussian() * 0.3 ) - 1.0 );
    mLocation = location;
    mLifespan = 100.0;
	mMass = 1.0;
	mImg = img;
}

void Particle::run()
{
	update();
	display();
}

void Particle::applyForce( ci::Vec2f force )
{
//	force /= mMass;
	mAcceleration += force;
}

// Method to update location
void Particle::update()
{
	mVelocity += mAcceleration;
	mLocation += mVelocity;
	mAcceleration *= 0;
	mLifespan -= 2.5;
	if( mLifespan < 0 ) mLifespan = 0;
}

// Method to display
void Particle::display()
{
	gl::enableAlphaBlending();		// allow transparency
	gl::color( ColorA8u( 255, 255, 255, mLifespan ) );
	gl::draw( mImg, mLocation - Vec2f(12.0, 12.0) );
	gl::color( Color::white() );	// reset the color
}

// Is the particle still useful?
bool Particle::isDead()
{
    if (mLifespan < 0.0) {
		return true;
    }
    else {
		return false;
    }
}