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
	
	float				mMutationRate;		// Mutation rate
	std::vector<Rocket>	mPopulation;        // Vector to hold the current population
	std::vector<Rocket>	mMatingPool;		// Vector which we will use for our "mating pool"
	int					mGenerations;       // Number of generations
	bool				mFinished;          // Are we finished evolving?
	int					mPerfectScore;
	
	
	
public:
	Population( float m, int num );
	void			live();
	void			naturalSelection();
	void			fitness();
	void			selection();
	void			reproduction();
	
	void			generate();
	std::string		getBest();
	bool			finished();
	int				getGenerations();
	float			getAverageFitness();
	std::string		allPhrases();

};