//
//  Confetti.cpp
//  NOC_4_05_ParticleSystemInheritancePolymorphism
//
//  Created by Greg Kepler on 10/18/13.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Confetti.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Confetti::Confetti()
{
	
}

Confetti::Confetti( ci::Vec2f location )
{
	mAcceleration = Vec2f( 0.0, 0.05 );
    mVelocity = Vec2f( randFloat( -1, 1 ), randFloat( -1.0, 0.0 ) );
    mLocation = location;
    mLifespan = 255.0;
}

void Confetti::run()
{
	Particle::update();
	display();
}

// Override the display method
void Confetti::display()
{	
	gl::enableAlphaBlending();
	Rectf rect = Rectf( -6, -6, 6, 6 );
	float theta = lmap( float(mLocation.x), 0.0f, float( getWindowWidth() ), 0.0f, float( M_PI ) * 4.0f );
	
	glPushMatrix();
	gl::translate( mLocation );
	gl::rotate( theta );
	
	gl::color( ColorA8u( 127, 127, 127, mLifespan ) );
	gl::drawSolidRect( rect );
	
	gl::color( ColorA8u( 0, 0, 0, mLifespan ) );
	gl::drawStrokedRect( rect );
	
	glPopMatrix();
}