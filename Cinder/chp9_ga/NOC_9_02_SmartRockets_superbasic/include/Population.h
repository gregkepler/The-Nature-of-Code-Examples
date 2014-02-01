//
//  Population.h
//  NOC_9_01_GA_Shakespeare
//
//  Created by Greg Kepler on 1/23/14.
//
//

#include "DNA.h"
#include "Rocket.h"

class Population {
	
	float					mMutationRate;		// Mutation rate
	std::vector<Rocket*>	mPopulation;        // Vector to hold the current population
	std::vector<Rocket*>	mMatingPool;		// Vector which we will use for our "mating pool"
	int						mGenerations;       // Number of generations
	bool					mFinished;          // Are we finished evolving?
	int						mPerfectScore;
	ci::Vec2f				*mTarget;
	
	
	
public:
	Population( float m, int num, ci::Vec2f* const target, int lifetime );
	void			live();
	void			naturalSelection();
	void			fitness();
	void			selection();
	void			reproduction();
	int				getGenerations();
	float			getMaxFitness();
};