//
//  Population.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "Population.h"
#include "cinder/CinderMath.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Population::Population( float m, int num, ci::Vec2f* const target, int lifetime )
{
    mMutationRate = m;
    mPopulation.resize( num );
    mGenerations = 0;
	
	mTarget = target;
	
	//make a new set of creatures
	for( int i = 0; i < mPopulation.size(); i++ )
	{
		Vec2f mLocation = Vec2f( getWindowWidth() / 2.0, getWindowHeight() + 20.0 );
		mPopulation[i] = std::make_shared<Rocket>( mLocation, new DNA( lifetime ), mTarget );
	}
}

void Population::live()
{
    // Run every rocket
    for( int i = 0; i < mPopulation.size(); i++ )
	{
		mPopulation[i]->run();
    }
}

// Calculate fitness for each creature
void Population::fitness()
{
    for( int i = 0; i < mPopulation.size(); i++ )
	{
		mPopulation[i]->fitness();
    }
}

// Generate a mating pool
void Population::selection()
{
	// Clear the ArrayList
    mMatingPool.clear();
	
    // Calculate total fitness of whole population
    float maxFitness = getMaxFitness();
	
    // Calculate fitness for each member of the population (scaled to value between 0 and 1)
    // Based on fitness, each member will get added to the mating pool a certain number of times
    // A higher fitness = more entries to mating pool = more likely to be picked as a parent
    // A lower fitness = fewer entries to mating pool = less likely to be picked as a parent
    for( int i = 0; i < mPopulation.size(); i++ )
	{
		float fitnessNormal = lmap( mPopulation[i]->getFitness(), 0.0f, maxFitness, 0.0f, 1.0f );
		int n = int( fitnessNormal * 100 );  // Arbitrary multiplier
		for( int j = 0; j < n; j++ )
		{
			mMatingPool.push_back( mPopulation[i] );
		}
    }
}

// Making the next generation
void Population::reproduction()
{
    // Refill the population with children from the mating pool
    for( int i = 0; i < mPopulation.size(); i++ )
	{
		// Sping the wheel of fortune to pick two parents
		int m = randInt( mMatingPool.size() );
		int d = randInt( mMatingPool.size() );
		// Pick two parents
		RocketRef mom = mMatingPool[m];
		RocketRef dad = mMatingPool[d];
		// Get their genes
		DNA *momgenes = mom->getDNA();
		DNA *dadgenes = dad->getDNA();
		// Mate their genes
		DNA *child = momgenes->crossover( dadgenes );
		// Mutate their genes
		child->mutate( mMutationRate );
		// Fill the new population with the new child
		Vec2f location = Vec2f( getWindowWidth() / 2.0, getWindowHeight() + 20.0 );
		
		mPopulation[i].reset(); // get rid of the old rocket
		mPopulation[i] = std::make_shared<Rocket>( location, child, mTarget );
    }
    mGenerations++;
}

int Population::getGenerations()
{
    return mGenerations;
}

// Find highest fintess for the population
float Population::getMaxFitness()
{
    float record = 0;
    for( int i = 0; i < mPopulation.size(); i++ )
	{
		if( mPopulation[i]->getFitness() > record )
		{
			record = mPopulation[i]->getFitness();
		}
    }
    return record;
}