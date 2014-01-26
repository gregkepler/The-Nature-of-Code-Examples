//
//  DNA.cpp
//
//  Created by Greg Kepler
//
//	Genetic Algorithm, Evolving Shakespeare

//	A class to describe a psuedo-DNA, i.e. genotype
//   Here, a virtual organism's DNA is an array of character.
//   Functionality:
//      -- convert DNA into a string
//      -- calculate DNA's "fitness"
//      -- mate DNA with another set of DNA
//      -- mutate DNA
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "DNA.h"

using namespace ci;
using namespace ci::app;
using namespace std;

DNA::DNA()
{
	DNA( 10 );
}

 // Constructor (makes a random DNA)
DNA::DNA( int num )
{
    mGenes.resize(num);
	Rand::randomize();
    for( int i = 0; i < mGenes.size(); i++ )
	{
		mGenes[i] = (char) randInt(32,128);  // Pick from range of chars
    }
	
}

// Converts character array to a String
string DNA::getPhrase()
{
	string str = string( mGenes.begin(), mGenes.end() );
    return str;			// convert the array to string
}

// Fitness function (returns floating point % of "correct" characters)
void DNA::calcFitness( string target )
{
	int score = 0;
	for( int i = 0; i < mGenes.size(); i++ ) {
        if( mGenes[i] == target.at( i ) ) {
			score++;
        }
	}
	
	mFitness = (float)score / (float)target.length();
}

// Crossover
DNA DNA::crossover(DNA partner)
{
    // A new child
    DNA child = DNA( mGenes.size() );
    
    int midpoint = randInt( mGenes.size() ); // Pick a midpoint
    
    // Half from one, half from the other
    for( int i = 0; i < mGenes.size(); i++ )
	{
		if( i > midpoint )	child.mGenes[i] = mGenes[i];
		else				child.mGenes[i] = partner.mGenes[i];
    }
    return child;
}

// Based on a mutation probability, picks a new random character
void DNA::mutate(float mutationRate)
{
    for( int i = 0; i < mGenes.size(); i++ )
	{
		if( randFloat() < mutationRate )
		{
			mGenes[i] = (char) randInt(32,128);
		}
    }
}