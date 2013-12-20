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

Particle::Particle( msa::physics::World2D* const world, Vec2f pos, bool locked ){
	mWorld = world;
	mPos = pos;
	mRadius = 16.0;
	mParticle = mWorld->makeParticle( pos );
	mParticle->setRadius( mRadius );
	if( locked ) mParticle->makeFixed();
	mDragging = false;
}

void Particle::startDrag( Vec2f pos )
{
	mDragging = true;
	mParticle->makeFixed();
	drag( pos );
}

void Particle::endDrag()
{
	mDragging = false;
	mParticle->makeFree();
}

void Particle::drag( Vec2f pos )
{
	mParticle->moveTo( pos );
}

void Particle::display()
{
	gl::color( Color8u::gray( 127 ) );
	gl::drawSolidEllipse( mParticle->getPosition(), mRadius, mRadius );
	gl::color( Color::black() );
	gl::drawStrokedEllipse( mParticle->getPosition(), mRadius, mRadius );
}


