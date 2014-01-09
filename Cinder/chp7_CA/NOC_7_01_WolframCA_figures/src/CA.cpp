//
//  CA.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "boost/algorithm/string.hpp"
#include "CA.h"

using namespace ci;
using namespace ci::app;
using namespace std;

const static int scl = 20;

CA::CA( int r[] )
{
	mRuleset = r;
    restart();
}

// Make a random ruleset
void CA::randomize()
{
    for( int i = 0; i < 8; i++ ) {
		mRuleset[i] = int( randInt( 2 ) );
    }
}

// Reset to generation 0
void CA::restart()
{
    for( int i = 0; i < mCells.size(); i++ )
	{
		mCells[i] = 0;
    }
    mCells[mCells.size()/2] = 1;    // We arbitrarily start with just the middle cell having a state of "1"
    mGeneration = 0;
}

// The process of creating the new generation
void CA::generate()
{
    // First we create an empty array for the new values
//    int[] nextgen = new int[cells.length];
	vector<int> nextGen;
	
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
void CA::render() {
    for( int i = 0; i < mCells.size(); i++ )
	{
		if( mCells[i] == 1 ) gl::color( Color::black() );
		else				gl::color( Color::white() );
		
		glPushMatrix();
		gl::translate( Vec2f( i * scl, mGeneration * scl ) );
		Rectf rect = Rectf( Vec2f::zero(), Vec2f( scl, scl ) );
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
    string s = to_string(a + b + c);
	// stol: http://en.cppreference.com/w/cpp/string/basic_string/stol
	int index = stol( s, NULL, 2);
    return mRuleset[index];
}

// The CA is done if it reaches the bottom of the screen
bool CA::finished()
{
    if( mGeneration > getWindowHeight() / scl ) {
		return true;
    }
    else {
		return false;
    }
}

