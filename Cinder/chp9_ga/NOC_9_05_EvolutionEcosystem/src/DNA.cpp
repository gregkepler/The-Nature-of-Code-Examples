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


 // Constructor (makes a random DNA)
DNA::DNA()
{
	// DNA is random floating point values between 0 and 1 (!!)
	Rand::randomize();
	
	mGenes.resize( 1 );
    for( int i = 0; i < mGenes.size(); i++ )
	{
		mGenes[i] = randFloat( 0.0, 1.0 );
    }
}

DNA::DNA( std::vector<float> genes )
{
	mGenes = genes;
}

DNA::~DNA()
{
	mGenes.clear();
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