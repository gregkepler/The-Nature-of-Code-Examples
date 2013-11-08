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
	mAcceleration = Vec2f( 0.0, 0.05 );
    mVelocity = Vec2f( randFloat( -1.0, 1.0 ), randFloat( -1.0, 0.0 ) );
	mVelocity *= 2.0;
    mLocation = location;
    mLifespan = 255.0;
	mImg = img;
}

void Particle::run()
{
	update();
	render();
}

void Particle::applyForce( ci::Vec2f force )
{
	mAcceleration += force;
}

// Method to update location
void Particle::update()
{
	mVelocity += mAcceleration;
	mLocation += mVelocity;
	mLifespan -= 2.0;
	if( mLifespan < 0 ) mLifespan = 0;
}

// Method to display
void Particle::render()
{
//	gl::enableAlphaBlending();		// allow transparency
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