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
	makeFixed();
    mWorld->addParticle( this );
	//mWorld->addConstraint( new msa::physics::Attraction2D( this, ) );
//    physics.addBehavior(new AttractionBehavior(this, width, 0.1));
}

void Attractor::attractParticle( msa::physics::Particle2D *const particle )
{
//	msa::physics::Attraction2D *attraction = new msa::physics::Attraction2D( this, particle, 0.1 );
//	attraction->setMinDistance( getWindowWidth() );
//	mWorld->addConstraint( attraction );
//	mWorld->makeAttraction( this, particle, 0.1 );
	mWorld->makeAttraction( this, particle, 1.0 );
	mWorld->getAttraction( 0 )->setMinDistance( getWindowWidth() );
}

void Attractor::display()
{
	gl::color( Color::black() );
	gl::drawSolidEllipse( getPosition(), mRadius, mRadius );
}
