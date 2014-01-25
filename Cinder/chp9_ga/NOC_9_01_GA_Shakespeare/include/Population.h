//
//  Population.h
//  NOC_9_01_GA_Shakespeare
//
//  Created by Greg Kepler on 1/23/14.
//
//

#include "DNA.h"

class Population {
	
	float				mMutationRate;		// Mutation rate
	std::vector<DNA>	mPopulation;        // Vector to hold the current population
	std::vector<DNA>	mMatingPool;		// Vector which we will use for our "mating pool"
	std::string			mTarget;            // Target phrase
	int					mGenerations;       // Number of generations
	bool				mFinished;          // Are we finished evolving?
	int					mPerfectScore;
	
	
	
public:
	Population( std::string p, float m, int num );
	void			naturalSelection();
	void			generate();
	void			calcFitness();
	std::string		getBest();
	bool			finished();
	int				getGenerations();
	float			getAverageFitness();
	std::string		allPhrases();
};