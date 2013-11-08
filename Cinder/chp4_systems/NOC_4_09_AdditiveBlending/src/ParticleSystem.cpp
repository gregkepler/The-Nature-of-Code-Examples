//
//  ParticleSystem.cpp
//
//  Created by Greg Kepler.
//
//

#include "cinder/app/AppBasic.h"
#include "ParticleSystem.h"

using namespace ci;
using namespace ci::app;
using namespace std;

ParticleSystem::ParticleSystem()
{
}

ParticleSystem::ParticleSystem( int num, ci::Vec2f location, ci::gl::Texture img )
{
	mOrigin = location;
	mParticles = vector<Particle>();
	mImg = img;
	
	for (int i = 0; i < num; i++) {
		addParticle();    // Add "num" amount of particles to the arraylist
    }
}

void ParticleSystem::applyForce( ci::Vec2f force )
{
	for( vector<Particle>::iterator it = mParticles.begin(); it != mParticles.end(); ++it ) {
		it->applyForce( force );
	}
}

void ParticleSystem::addParticle()
{
	mParticles.push_back( Particle( mOrigin, mImg ) );
}

void ParticleSystem::run()
{
	for( vector<Particle>::iterator it = mParticles.end()-1; it != mParticles.begin(); --it ) {
		it->run();
		if ( it->isDead() ) {
			// must provide iterator in the erase function
			mParticles.erase( it );
		}
	}
}