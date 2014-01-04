//
//  Path.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "Path.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Path::Path()
{
	// Arbitrary radius of 20
    mRadius = 20.0;
    mStart = Vec2f( 0.0, getWindowHeight() / 3 );
	mEnd = Vec2f( getWindowWidth(), 2 * getWindowHeight() / 3 );
}

// Add a point to the path
void Path::addPoint( ci::Vec2f pt ) {
    mPoints.push_back( pt );
}

Vec2f Path::getStart()
{
	return mPoints[0];
}

Vec2f Path::getEnd() {
	return mPoints[mPoints.size() - 1];
}

// Draw the path
void Path::display()
{		
	// Draw thick line for radius
	gl::color( Color8u::gray( 175 ) );
	gl::lineWidth( mRadius * 2 );
	gl::begin( GL_LINE_STRIP );
	for( Vec2f v : mPoints )
	{
		gl::vertex( v );
	}
	gl::end();
	
	// Draw thin line for center of path
	gl::color( Color::black() );
	gl::lineWidth( 1.0 );
	gl::begin( GL_LINE_STRIP );
    for( Vec2f v : mPoints ) {
		gl::vertex( v );
    }
	gl::end();
}

