//
//  ParticleSystem.h
//  NOC_4_03_ParticleSystemClass
//
//  Created by Greg Kepler on 10/16/13.
//
//

#include "cinder/app/AppBasic.h"
#include "Particle.h"

class ParticleSystem {
public:
	ParticleSystem();
	ParticleSystem( ci::Vec2f location );
	
	void addParticle();
	void run();
	
private:
	ci::Vec2f mOrigin;
	std::vector<Particle> mParticles;
};