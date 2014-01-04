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

void Path::display()
{	
	glLineWidth( mRadius * 2.0 );
	gl::color( ColorA8u( 0, 0, 0, 100 ) );
	gl::drawLine( mStart, mEnd );
	
	gl::lineWidth( 1.0 );
	gl::color( Color::black() );
	gl::drawLine( mStart, mEnd );	
}
