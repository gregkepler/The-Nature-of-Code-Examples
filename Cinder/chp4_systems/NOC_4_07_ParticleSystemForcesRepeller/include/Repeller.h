//
//  Repeller.h
//  NOC_4_07_ParticleSystemForcesRepeller
//
//  Created by Greg Kepler on 11/4/13.
//
//

#pragma once

#include "cinder/app/AppBasic.h"
#include "Particle.h"

class Repeller {
public:
	Repeller();
	Repeller( ci::Vec2f location );
	
	void display();
	ci::Vec2f repel( Particle p );
	
private:
	float mGravity;
	ci::Vec2f mLocation;
};