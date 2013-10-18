//
//  ParticleSystem.cpp
//  NOC_4_03_ParticleSystemClass
//
//  Created by Greg Kepler on 10/16/13.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "ParticleSystem.h"
#include "Confetti.h"

using namespace ci;
using namespace ci::app;
using namespace std;

ParticleSystem::ParticleSystem()
{
	
}

ParticleSystem::ParticleSystem( ci::Vec2f location )
{
	mOrigin = location;
	mParticles = vector<Particle>();
}

void ParticleSystem::addParticle()
{
//	mParticles.push_back( Particle( mOrigin ) );
	
	float r = randFloat();
    if (r < 0.5) {
		mParticles.push_back( Particle( mOrigin ) );
    }
    else {
		mParticles.push_back( Confetti( mOrigin ) );
    }
}

void ParticleSystem::run()
{
	for( vector<Particle>::iterator it = mParticles.begin(); it != mParticles.end(); ++it ) {
		it->run();
		if ( it->isDead() ) {
			// must provide iterator in the erase function
			mParticles.erase( it );
		}
	}
}