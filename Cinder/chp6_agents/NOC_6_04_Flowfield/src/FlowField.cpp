//
//  FlowField.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "cinder/Perlin.h"
#include "FlowField.h"

using namespace ci;
using namespace ci::app;
using namespace std;

FlowField::FlowField( int resolution )
{
	mResolution = resolution;
    // Determine the number of columns and rows based on sketch's width and height
    mCols = getWindowWidth() / mResolution;
    mRows = getWindowHeight() / mResolution;
	
	// initialize the vector by letting it know the size of it
	mField = vector< vector<Vec2f> >( mCols, vector<Vec2f>( mRows ) );
    init();
}

void FlowField::init()
{
	// Reseed noise so we get a new flow field every time
	Perlin p = Perlin();
	p.setSeed( randInt( 10000 ) );
	
	float xOff = 0;
    for( int i = 0; i < mCols; i++ )
	{
		float yOff = 0;
		for( int j = 0; j < mRows; j++)
		{
			float theta = lmap( p.noise( xOff, yOff ), 0.0f, 1.0f, 0.0f, float( M_PI * 2.0f ) );
			// Polar to cartesian coordinate transformation to get x and y components of the vector
			mField[i][j] = Vec2f( cos( theta ), sin( theta ) );
			yOff += 0.1;
		}
		xOff += 0.1;
    }
}

// Draw every vector
void FlowField::display()
{
    for (int i = 0; i < mCols; i++)
	{
		for (int j = 0; j < mRows; j++)
		{
			drawVector( mField[i][j], i * mResolution, j * mResolution, mResolution - 2 );
		}
    }
}

// Renders a vector object 'v' as an arrow and a location 'x,y'
void FlowField::drawVector( Vec2f v, float x, float y, float scale )
{
	glPushMatrix();
    float arrowsize = 4.0;
    // Translate to location to render vector
	gl::translate( x, y );
	gl::color( ColorA8u( 0, 0 ,0, 100 ) );
    // Call vector heading function to get direction (note that pointing up is a heading of 0) and rotate
	gl::rotate( toDegrees( atan2( v.y, v.x ) ) );
	
    // Calculate length of vector & scale it to be bigger or smaller if necessary
    float len = v.length() * scale;
	
    // Draw three lines to make an arrow (draw pointing up since we've rotate to the proper direction)
	gl::drawLine( Vec2f( 0.0, 0.0), Vec2f( len, 0.0 ) );
	gl::drawLine( Vec2f( len, 0.0), Vec2f( len - arrowsize, +arrowsize / 2 ) );
	gl::drawLine( Vec2f( len, 0.0), Vec2f( len - arrowsize, -arrowsize / 2 ) );
    glPopMatrix();
}

Vec2f FlowField::lookup( Vec2f lookup )
{
    int column = int( constrain( int( lookup.x ) / mResolution, 0, mCols - 1 ) );
    int row = int( constrain( int( lookup.y ) / mResolution, 0, mRows - 1 ) );
    return mField[column][row];
}
