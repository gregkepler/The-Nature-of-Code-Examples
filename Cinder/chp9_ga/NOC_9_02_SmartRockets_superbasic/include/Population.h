//
//  Population.h
//
//  Created by Greg Kepler
//
//

#include "DNA.h"
#include "Rocket.h"

class Population {
	
public:
	Population( float m, int num, ci::Vec2f* const target, int lifetime );
	~Population(){};
	void			live();
	void			fitness();
	void			selection();
	void			reproduction();
	int				getGenerations();
	float			getMaxFitness();
	
private:
	float					mMutationRate;		// Mutation rate
	std::vector<RocketRef>	mPopulation;        // Vector to hold the current population
	std::vector<RocketRef>	mMatingPool;		// Vector which we will use for our "mating pool"
	int						mGenerations;       // Number of generations
	ci::Vec2f				*mTarget;
};