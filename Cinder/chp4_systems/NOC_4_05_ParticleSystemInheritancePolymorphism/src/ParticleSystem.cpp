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
	mParticles = vector<Particle*>();
}

void ParticleSystem::addParticle()
{
	float r = randFloat();
    if (r < 0.5) {
		mParticles.insert( mParticles.begin(), new Particle( mOrigin ) ); // insert to the front of the vector so that it's drawn first
    } else {
		mParticles.insert( mParticles.begin(), new Confetti( mOrigin ) );
    }
}

void ParticleSystem::run()
{
	// iterating through a vector (of pointers)
	for( vector<Particle*>::iterator it = mParticles.begin(); it != mParticles.end(); ) {
		(*it)->run();
		if ( (*it)->isDead() ) {
			// delete the pointer
			delete *it;
			// remove the pointer from the vector
			it = mParticles.erase( it );
		}else{
			++it;
		}
	}
}