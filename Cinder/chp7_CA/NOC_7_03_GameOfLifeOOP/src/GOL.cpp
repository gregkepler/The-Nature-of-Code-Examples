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
#include "Cell.h"

using namespace ci;
using namespace ci::app;
using namespace std;

GOL::GOL()
{
	mWidth = 8;
	// Initialize rows, columns and set-up arrays
    mColumns = getWindowWidth() / mWidth;
    mRows = getWindowHeight() / mWidth;
	mBoard.resize( mColumns, vector<Cell>( mRows, Cell( Vec2f( 0, 0 ), mWidth ) ) );
	
    // Call function to fill array with random values 0 or 1
    init();
}

void GOL::init()
{
	for( int i = 0; i < mColumns; i++ )
	{
		for( int j = 0; j < mRows; j++ )
		{
			mBoard[i][j] = Cell( Vec2f( i * mWidth, j * mWidth ), mWidth );
		}
	}
}

// The process of creating the new generation
void GOL::generate()
{
	for ( int i = 0; i < mColumns;i++) {
		for ( int j = 0; j < mRows;j++) {
			mBoard[i][j].savePrevious();
		}
    }
	
	// Loop through every spot in our 2D array and check spots neighbors
    for( int x = 0; x < mColumns; x++ )
	{
		for( int y = 0; y < mRows; y++ )
		{
			// Add up all the states in a 3x3 surrounding grid
			int neighbors = 0;
			for( int i = -1; i <= 1; i++ )
			{
				for( int j = -1; j <= 1; j++ )
				{
					neighbors += mBoard[( x + i + mColumns ) % mColumns][( y + j + mRows ) % mRows].mPrevious;
				}
			}
			
			// A little trick to subtract the current cell's state since
			// we added it in the above loop
			neighbors -= mBoard[x][y].mPrevious;
			
			// Rules of Life
			if      ( ( mBoard[x][y].mState == 1 ) && ( neighbors <  2 ) ) mBoard[x][y].newState(0);           // Loneliness
			else if ( ( mBoard[x][y].mState == 1 ) && ( neighbors >  3 ) ) mBoard[x][y].newState(0);           // Overpopulation
			else if ( ( mBoard[x][y].mState == 0 ) && ( neighbors == 3 ) ) mBoard[x][y].newState(1);           // Reproduction
		}
    }
}

// This is the easy part, just draw the cells, fill 255 for '1', fill 0 for '0'
void GOL::display()
{
	for( int i = 0; i < mColumns; i++ )
	{
		for ( int j = 0; j < mRows; j++ )
		{
			mBoard[i][j].display();
		}
    }
}

