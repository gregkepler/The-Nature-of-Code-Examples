//
//  DNA.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "DNA.h"

using namespace ci;
using namespace ci::app;
using namespace std;

const int LEN = 20;

 // Constructor (makes a random DNA)
DNA::DNA()
{
	// DNA is random floating point values between 0 and 1 (!!)
	Rand::randomize();
	
	mMaxforce = 0.1f;
	mGenes.resize( LEN );
    for( int i = 0; i < mGenes.size(); i++ )
	{
		mGenes[i] = randFloat( 0.0, 1.0 );
    }
}

DNA::DNA( std::vector<float> genes )
{
	mGenes = genes;
}

// Crossover
// Creates new DNA sequence from two (this &
DNA* DNA::crossover( DNA* const partner )
{
	std::vector<float> child;
	child.resize( mGenes.size() );
	
	int crossover = randInt( mGenes.size() );
    for (int i = 0; i < mGenes.size(); i++) {
		if (i > crossover) child[i] = mGenes[i];
		else               child[i] = partner->mGenes[i];
    }
    DNA *newgenes = new DNA( child );
    return newgenes;
}

// Based on a mutation probability, picks a new random rotation
void DNA::mutate( float m )
{
    for( int i = 0; i < mGenes.size(); i++ )
	{
		if( randFloat() < m )
		{
			 mGenes[i] = randFloat( 0.0, 1.0 );
		}
    }
}