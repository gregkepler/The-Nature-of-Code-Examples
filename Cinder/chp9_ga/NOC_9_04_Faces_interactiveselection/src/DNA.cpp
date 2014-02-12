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

// Crossover
DNA* DNA::crossover( DNA* const partner )
{
    // A new child
    DNA *child = new DNA( );
    int midpoint = randInt( mGenes.size() ); // Pick a midpoint
    
    // Half from one, half from the other
    for( int i = 0; i < mGenes.size(); i++ )
	{
		if( i > midpoint )	child->mGenes[i] = mGenes[i];
		else				child->mGenes[i] = partner->mGenes[i];
    }
    return child;
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