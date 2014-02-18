//
//  World.h
//  NOC_9_05_EvolutionEcosystem
//
//  Created by Greg Kepler on 2/17/14.
//
//

#include "cinder/app/AppNative.h"
#include "Bloop.h"
#include "Food.h"

class World {
	
	std::vector<Bloop*>	mBloops;	// A vector for all the creatures
	Food				*mFood;
	
public:
	World( int num );
	void	run();
	void	born( ci::Vec2f pos );
};