//
//  ParticleSystem.h
//  NOC_4_03_ParticleSystemClass
//
//  Created by Greg Kepler on 10/16/13.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/Texture.h"
#include "Particle.h"

class ParticleSystem {
public:
	ParticleSystem();
	ParticleSystem( ci::Vec2f location,  ci::gl::Texture img );
	
	void applyForce( ci::Vec2f force );
	void addParticle();
	void run();
	
private:
	ci::Vec2f				mOrigin;
	std::vector<Particle>	mParticles;
	ci::gl::Texture			mImg;
};