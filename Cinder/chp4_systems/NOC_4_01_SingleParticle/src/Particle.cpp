//
//  Particle.cpp
//  NOC_4_01_SingleParticle
//
//  Created by Greg Kepler on 10/12/13.
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

Particle::Particle( Vec2f l )
{
	mAcceleration = Vec2f( 0.0, 0.05f );
	mVelocity = Vec2f( randFloat(-1.0, 1.0), randFloat(-1.0, 0.0) );
	mLocation = l;
	mLifespan = 255.0;
}

void Particle::run()
{
	update();
	display();
}

void Particle::update()
{
	mVelocity += mAcceleration;
	mLocation += mVelocity;
	mLifespan -= 2.0;
}

void Particle::display()
{
	gl::enableAlphaBlending();
	
	gl::color( ColorA8u( 127, 127, 127, mLifespan ) );
	gl::drawSolidEllipse( mLocation, 6, 6);
	
	gl::color( ColorA8u( 0, 0, 0, mLifespan ) );
	glLineWidth( 2.0f );
	gl::drawStrokedEllipse( mLocation, 6, 6);
}

bool Particle::isDead()
{
	if( mLifespan < 0.0 ){
		return true;
	}else{
		return false;
	}
}