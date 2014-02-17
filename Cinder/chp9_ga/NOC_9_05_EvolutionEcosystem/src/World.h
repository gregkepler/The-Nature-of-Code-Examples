//
//  World.h
//  NOC_9_05_EvolutionEcosystem
//
//  Created by Greg Kepler on 2/17/14.
//
//

#include "cinder/app/AppNative.h"

class World {
	
	public:
	World( int num );
	void	run();
	void	born( ci::Vec2f pos );
};