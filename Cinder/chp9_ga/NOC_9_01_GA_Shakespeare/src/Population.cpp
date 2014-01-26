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

Population::Population( string p, float m, int num )
{
	mTarget = p;
    mMutationRate = m;
    mPopulation.resize( num );
    for( int i = 0; i < mPopulation.size(); i++)
	{
		mPopulation[i] = DNA( mTarget.size() );
    }
    calcFitness();
    mFinished = false;
    mGenerations = 0;
    mPerfectScore = 1;
}

// Fill our fitness array with a value for every member of the population
void Population::calcFitness()
{
    for( int i = 0; i < mPopulation.size(); i++ )
	{
		mPopulation[i].fitness( mTarget );
    }
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