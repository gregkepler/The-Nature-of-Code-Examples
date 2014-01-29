//
//  Population.cpp
//  NOC_9_01_GA_Shakespeare
//
//  Created by Greg Kepler on 1/23/14.
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "Population.h"
#include "cinder/CinderMath.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Population::Population( float m, int num )
{
    mMutationRate = m;
    mPopulation.resize( num );
    mFinished = false;
    mGenerations = 0;
	
	//make a new set of creatures
	for( int i = 0; i < mPopulation.size(); i++ )
	{
		Vec2f mLocation = Vec2f( getWindowWidth() / 2.0, getWindowHeight() + 20.0 );
		mPopulation[i] = Rocket( location, DNA() );
	}
}

void Population::live()
{
    // Run every rocket
    for( int i = 0; i < mPopulation.length; i++ )
	{
		mPopulation[i].run();
    }
}

// Calculate fitness for each creature
void Population::fitness()
{
    for( int i = 0; i < mPopulation.size(); i++ )
	{
		mPopulation[i].fitness();
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
    for( int i = 0; i < mPopulation.length; i++ )
	{
		float fitnessNormal = lmap( population[i].getFitness(), 0.0f, maxFitness, 0.0f, 1.0f );
		int n = int( fitnessNormal * 100 );  // Arbitrary multiplier
		for( int j = 0; j < n; j++ )
		{
			mMatingPool.add( mPopulation[i]  );
		}
    }
}

// Making the next generation
void Population::reproduction()
{
    // Refill the population with children from the mating pool
    for (int i = 0; i < mPopulation.length; i++)
	{
		// Sping the wheel of fortune to pick two parents
		int m = int(random(matingPool.size()));
		int d = int(random(matingPool.size()));
		// Pick two parents
		Rocket mom = matingPool.get(m);
		Rocket dad = matingPool.get(d);
		// Get their genes
		DNA momgenes = mom.getDNA();
		DNA dadgenes = dad.getDNA();
		// Mate their genes
		DNA child = momgenes.crossover(dadgenes);
		// Mutate their genes
		child.mutate(mutationRate);
		// Fill the new population with the new child
		PVector location = new PVector(width/2,height+20);
		population[i] = new Rocket(location, child);
    }
    generations++;
}












// Generate a mating pool
void Population::naturalSelection()
{
    // Clear the vector
    mMatingPool.clear();
	
    float maxFitness = 0.0f;
    for( int i = 0; i < mPopulation.size(); i++)
	{
		if( mPopulation[i].mFitness > maxFitness )
		{
			maxFitness = mPopulation[i].mFitness;
		}
    }
	
    // Based on fitness, each member will get added to the mating pool a certain number of times
    // a higher fitness = more entries to mating pool = more likely to be picked as a parent
    // a lower fitness = fewer entries to mating pool = less likely to be picked as a parent
    for( int i = 0; i < mPopulation.size(); i++ )
	{
		float fitness = lmap( mPopulation[i].mFitness, 0.0f, maxFitness, 0.0f, 1.0f );
		int n = int( fitness * 100 );			// Arbitrary multiplier, we can also use monte carlo method
		for( int j = 0; j < n; j++ ) {           // and pick two random numbers
			mMatingPool.push_back( mPopulation[i] );
		}
    }
}

// Create a new generation
void Population::generate()
{
    // Refill the population with children from the mating pool
    for( int i = 0; i < mPopulation.size(); i++ )
	{
		int a = randInt( mMatingPool.size() );
		int b = randInt( mMatingPool.size() );
		
		DNA partnerA = mMatingPool[a];
		DNA partnerB = mMatingPool[b];
		DNA child = partnerA.crossover( partnerB );
		child.mutate( mMutationRate );
		mPopulation[i] = child;
    }
    mGenerations++;
}

// Compute the current "most fit" member of the population
string Population::getBest()
{
    float worldrecord = 0.0;
    int index = 0;
    for( int i = 0; i < mPopulation.size(); i++) {
		if( mPopulation[i].mFitness > worldrecord) {
			index = i;
			worldrecord = mPopulation[i].mFitness;
		}
    }
    
    if( worldrecord == mPerfectScore ) mFinished = true;
    return mPopulation[index].getPhrase();
}

bool Population::finished()
{
    return mFinished;
}

int Population::getGenerations()
{
    return mGenerations;
}

// Compute average fitness for the population
float Population::getAverageFitness()
{
    float total = 0;
    for (int i = 0; i < mPopulation.size(); i++) {
		total += mPopulation[i].mFitness;
    }
    return total / ( mPopulation.size() );
}

string Population::allPhrases()
{
    string everything = "";
    
    int displayLimit = MIN( mPopulation.size(), 50 );
	
    
    for (int i = 0; i < displayLimit; i++)
	{
		everything += mPopulation[i].getPhrase() + "\n";
    }
    return everything;
}