//
//  KochFractal.cpp
//
//  Created by Greg Kepler
//
//

#include "KochFractal.h"

using namespace ci;
using namespace ci::app;
using namespace std;

KochFractal::KochFractal()
{
	mStart = Vec2f( 0, getWindowHeight() - 20.0 );
	mEnd = Vec2f( getWindowWidth(), getWindowHeight() - 20.0 );
	restart();
}

void KochFractal::nextLevel()
{
    // For every line that is in the arraylist
    // create 4 more lines in a new arraylist
	mLines = iterate( mLines );
    mCount++;
}

void KochFractal::restart()
{
    mCount = 0;			// Reset count
    mLines.clear();		// Empty the array list
    mLines.push_back( new KochLine( mStart, mEnd ) );  // Add the initial line (from one end PVector to the other)
}

int KochFractal::getCount() {
    return mCount;
}

// This is easy, just draw all the lines
void KochFractal::render()
{
    for( KochLine *l : mLines) {
		l->display();
    }
}

// This is where the **MAGIC** happens
// Step 1: Create an empty arraylist
// Step 2: For every line currently in the arraylist
//   - calculate 4 line segments based on Koch algorithm
//   - add all 4 line segments into the new arraylist
// Step 3: Return the new arraylist and it becomes the list of line segments for the structure

// As we do this over and over again, each line gets broken into 4 lines, which gets broken into 4 lines, and so on. . .
vector<KochLine*> KochFractal::iterate( vector<KochLine*> before )
{
	vector<KochLine*> now;	// Create emtpy list
	for (KochLine *l : before) {
		// Calculate 5 koch PVectors (done for us by the line object)
		Vec2f a = l->kochA();
		Vec2f b = l->kochB();
		Vec2f c = l->kochC();
		Vec2f d = l->kochD();
		Vec2f e = l->kochE();
		// Make line segments between all the PVectors and add them
		now.push_back( new KochLine( a, b ) );
		now.push_back( new KochLine( b, c ) );
		now.push_back( new KochLine( c, d ) );
		now.push_back( new KochLine( d, e ) );
	}
	return now;

}
