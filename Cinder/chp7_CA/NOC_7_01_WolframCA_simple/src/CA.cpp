//
//  CA.cpp
//
//  Created by Greg Kepler
//
//	A class to manage the CA
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "boost/algorithm/string.hpp"
#include "CA.h"

using namespace ci;
using namespace ci::app;
using namespace std;

CA::CA()
{
	mRuleset = {0, 1, 0, 1, 1, 0, 1, 0};     // An array to store the ruleset, for example {0,1,1,0,1,1,0,1};
	mWidth = 10;
	mCells.resize( getWindowWidth() / mWidth, 0 );
	mCells[mCells.size()/2] = 1;    // We arbitrarily start with just the middle cell having a state of "1"
	mGeneration = 0;
}

// The process of creating the new generation
void CA::generate()
{
    // First we create an empty array for the new values
	vector<int> nextGen;
	for( int i = 0; i < mCells.size(); i++ ) {
		nextGen.push_back(0);
    }
	
    // For every spot, determine new state by examing current state, and neighbor states
    // Ignore edges that only have one neighor
    for( int i = 1; i < mCells.size()-1; i++ )
	{
		int left = mCells[i-1];   // Left neighbor state
		int me = mCells[i];       // Current state
		int right = mCells[i+1];  // Right neighbor state
		nextGen[i] = rules( left, me, right ); // Compute next generation state based on ruleset
    }
    // The current generation is the new generation
    mCells = nextGen;
    mGeneration++;
}

// This is the easy part, just draw the cells, fill 255 for '1', fill 0 for '0'
void CA::display() {
    for( int i = 0; i < mCells.size(); i++ )
	{
		if( mCells[i] == 1 ) gl::color( Color::black() );
		else				gl::color( Color::white() );
		
		glPushMatrix();
		gl::translate( Vec2f( i * mWidth, mGeneration * mWidth ) );
		Rectf rect = Rectf( Vec2f::zero(), Vec2f( mWidth, mWidth ) );
		gl::drawSolidRect( rect );
		
		gl::color( Color::black() );
		gl::drawStrokedRect( rect );
		glPopMatrix();
    }
}

// Implementing the Wolfram rules
// Could be improved and made more concise, but here we can explicitly see what is going on for each case
int CA::rules (int a, int b, int c)
{
    if( a == 1 && b == 1 && c == 1 ) return mRuleset[0];
    if( a == 1 && b == 1 && c == 0 ) return mRuleset[1];
    if( a == 1 && b == 0 && c == 1 ) return mRuleset[2];
    if( a == 1 && b == 0 && c == 0 ) return mRuleset[3];
    if( a == 0 && b == 1 && c == 1 ) return mRuleset[4];
    if( a == 0 && b == 1 && c == 0 ) return mRuleset[5];
    if( a == 0 && b == 0 && c == 1 ) return mRuleset[6];
    if( a == 0 && b == 0 && c == 0 ) return mRuleset[7];
    return 0;
}


