//
//  Confetti.h
//  NOC_4_05_ParticleSystemInheritancePolymorphism
//
//  Created by Greg Kepler on 10/18/13.
//
//

#include "Particle.h"

class Confetti : public Particle {
public:
	Confetti();
	Confetti( ci::Vec2f location );
	
	void display();

};