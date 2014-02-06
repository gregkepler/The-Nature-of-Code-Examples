//
//  Population.h
//
//  Created by Greg Kepler
//
//

#include "DNA.h"
#include "Rocket.h"
#include "Obstacle.h"

class Population {
	
	float					mMutationRate;		// Mutation rate
	std::vector<Rocket*>	mPopulation;        // Vector to hold the current population
	std::vector<Rocket*>	mMatingPool;		// Vector which we will use for our "mating pool"
	int						mGenerations;       // Number of generations
	Obstacle				*mTarget;
	
	
	
public:
	Population( float m, int num, Obstacle* const target, int lifetime );
	void			live( std::vector<Obstacle*>* const obstacles );
	bool			targetReached();
	void			fitness();
	void			selection();
	void			reproduction();
	int				getGenerations();
	float			getMaxFitness();
};