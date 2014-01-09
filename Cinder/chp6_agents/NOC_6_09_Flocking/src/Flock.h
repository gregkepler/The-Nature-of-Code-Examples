//
//  Flock.h
//  NOC_6_09_Flocking
//
//  Created by Greg Kepler
//
//	Does very little, simply manages the vector of all the boids
//
//

#include "Boid.h"

class Flock {
	std::vector<Boid*>	mBoids;
	
public:
	Flock();
	void	run();
	void	addBoid( Boid* const b );
};