//
//  Attractor.cpp
//  NOC_5_13_AttractRepel
//
//  Created by Greg Kepler on 12/22/13.
//
//

#include "Attractor.h"
#include "MSAPhysicsConstraint.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Attractor::Attractor( msa::physics::World2D* const world, Vec2f loc )
{
	mWorld = world;
	moveTo( loc );
	mRadius = 24.0;
    mWorld->addParticle( this );
}

void Attractor::attractParticle( msa::physics::Particle2D *const particle )
{
	mWorld->makeAttraction( this, particle, 0.1 );
	mWorld->getAttraction( mWorld->numberOfAttractions() - 1 )->setMaxDistance( getWindowWidth() );
}

void Attractor::display()
{
	gl::color( Color::black() );
	gl::drawSolidEllipse( getPosition(), mRadius, mRadius );
}
