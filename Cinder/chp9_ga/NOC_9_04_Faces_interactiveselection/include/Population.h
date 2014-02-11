//
//  Population.h
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "DNA.h"
#include "Face.h"

class Population {
	
	float					mMutationRate;		// Mutation rate
	std::vector<Face*>		mPopulation;        // Vector to hold the current population
	std::vector<Face*>		mMatingPool;		// Vector which we will use for our "mating pool"
	int						mGenerations;       // Number of generations
	
	
	
public:
	Population( float m, int num );
	
	void			display();
	void			rollover( ci::Vec2f mousePos );
	void			selection();
	void			reproduction();
	int				getGenerations();
	float			getMaxFitness();




};