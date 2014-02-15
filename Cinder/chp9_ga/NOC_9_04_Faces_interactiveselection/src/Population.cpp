//
//  Population.cpp
//
//  Created by Greg Kepler
//
//	A class to describe a population of faces
//	this hasn't changed very much from example to example
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "Population.h"
#include "cinder/CinderMath.h"

using namespace ci;
using namespace ci::app;
using namespace std;

// Create the population
Population::Population( float m, int num )
{
    mMutationRate = m;
    mPopulation.resize( num );
    mGenerations = 0;
	
	//make a new set of creatures
	for( int i = 0; i < mPopulation.size(); i++ )
	{
		mPopulation[i] = new Face( new DNA(), Vec2f( 50.0 + i * 75.0, 60.0 ) );
	}
}

// Display all faces
void Population::display()
{
    for (int i = 0; i < mPopulation.size(); i++) {
		mPopulation[i]->display();
    }
}

// Are we rolling over any of the faces?
void Population::rollover( ci::Vec2f mousePos )
{
	for (int i = 0; i < mPopulation.size(); i++) {
		mPopulation[i]->rollover( mousePos );
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
		Face *mom = mMatingPool[m];
		Face *dad = mMatingPool[d];
		
		// Get their genes
		DNA *momgenes = mom->getDNA();
		DNA *dadgenes = dad->getDNA();
		
		// Mate their genes
		DNA *child = momgenes->crossover( dadgenes );
		// Mutate their genes
		child->mutate( mMutationRate );
		
		// Fill the new population with the new child
		mPopulation[i] = new Face( child, Vec2f( 50.0 + i * 75.0, 60.0 ) );
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