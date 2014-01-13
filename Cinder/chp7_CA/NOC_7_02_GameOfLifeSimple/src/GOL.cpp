//
//
//  Created by Greg Kepler
//
//	A class to manage the GOL
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "boost/algorithm/string.hpp"
#include "GOL.h"

using namespace ci;
using namespace ci::app;
using namespace std;

GOL::GOL()
{
	mWidth = 8;
	// Initialize rows, columns and set-up arrays
    mColumns = getWindowWidth() / mWidth;
    mRows = getWindowHeight() / mWidth;
	mBoard.resize( mColumns, vector<int>( mRows, 0 ) );
	
    // Call function to fill array with random values 0 or 1
    init();
}

void GOL::init()
{
	for( int i = 1; i < mColumns - 1; i++ )
	{
		for( int j = 1; j < mRows - 1; j++ )
		{
			mBoard[i][j] = randInt( 2 );
		}
	}
}

// The process of creating the new generation
void GOL::generate()
{
    std::vector<std::vector<int>> next( mColumns, vector<int>( mRows, 0 ) );
	
	// Loop through every spot in our 2D array and check spots neighbors
    for( int x = 1; x < mColumns - 1; x++ )
	{
		for( int y = 1; y < mRows - 1; y++ )
		{
			// Add up all the states in a 3x3 surrounding grid
			int neighbors = 0;
			for( int i = -1; i <= 1; i++ )
			{
				for( int j = -1; j <= 1; j++ )
				{
					neighbors += mBoard[x+i][y+j];
				}
			}
			
			// A little trick to subtract the current cell's state since
			// we added it in the above loop
			neighbors -= mBoard[x][y];
			
			// Rules of Life
			if      ( ( mBoard[x][y] == 1 ) && ( neighbors <  2 ) ) next[x][y] = 0;           // Loneliness
			else if ( ( mBoard[x][y] == 1 ) && ( neighbors >  3 ) ) next[x][y] = 0;           // Overpopulation
			else if ( ( mBoard[x][y] == 0 ) && ( neighbors == 3 ) ) next[x][y] = 1;           // Reproduction
			else next[x][y] = mBoard[x][y];  // Stasis
		}
    }
	
    // Next is now our board
    mBoard = next;
}

// This is the easy part, just draw the cells, fill 255 for '1', fill 0 for '0'
void GOL::display()
{
	for( int i = 0; i < mColumns; i++ )
	{
		for ( int j = 0; j < mRows; j++ )
		{
			if( mBoard[i][j] == 1 ) 	gl::color( Color::black() );
			else						gl::color( Color::white() );
			
			glPushMatrix();
			gl::translate( Vec2f( i * mWidth, j * mWidth ) );
			Rectf rect = Rectf( Vec2f::zero(), Vec2f( mWidth, mWidth ) );
			gl::drawSolidRect( rect );
			
			gl::color( Color::black() );
			gl::drawStrokedRect( rect );
			glPopMatrix();
		}
    }
}

