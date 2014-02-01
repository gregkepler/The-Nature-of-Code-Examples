//
//  DNA.cpp
//  NOC_9_01_GA_Shakespeare
//
//  Created by Greg Kepler on 1/23/14.
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "DNA.h"

using namespace ci;
using namespace ci::app;
using namespace std;

 // Constructor (makes a random DNA)
DNA::DNA( int lifetime )
{
	Rand::randomize();
	
	mMaxforce = 0.1f;
	mGenes.resize(lifetime);
    for( int i = 0; i < mGenes.size(); i++ )
	{
		float angle = randFloat( 360.0 );
		mGenes[i] = Vec2f( cos( angle ), sin( angle ) );
		mGenes[i] *= randFloat( 0, mMaxforce );
    }
}


// Crossover
DNA* DNA::crossover( DNA* const partner )
{
    // A new child
    DNA *child = new DNA( mGenes.size() );
    
    int midpoint = randInt( mGenes.size() ); // Pick a midpoint
    
    // Half from one, half from the other
    for( int i = 0; i < mGenes.size(); i++ )
	{
		if( i > midpoint )	child->mGenes[i] = mGenes[i];
		else				child->mGenes[i] = partner->mGenes[i];
    }
    return child;
}

// Based on a mutation probability, picks a new random character
void DNA::mutate( float m )
{
    for( int i = 0; i < mGenes.size(); i++ )
	{
		if( randFloat() < m )
		{
			float angle = randFloat( M_PI * 2 );
			mGenes[i] = Vec2f( cos( angle ), sin( angle ) );
			mGenes[i] *= randFloat( 0.0, mMaxforce );
		}
    }
}