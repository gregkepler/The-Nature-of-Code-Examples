//
//  Repeller.h
//  NOC_4_07_ParticleSystemForcesRepeller
//
//  Created by Greg Kepler on 11/4/13.
//
//

#include "cinder/app/AppBasic.h"

class Repeller {
public:
	Repeller();
	Repeller( ci::Vec2f location );
	
private:
	const float Gravity = 100;
	ci::Vec2f mLocation;
	float r;
};