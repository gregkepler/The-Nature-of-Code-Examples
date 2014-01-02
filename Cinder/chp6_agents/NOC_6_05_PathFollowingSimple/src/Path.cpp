//
//  Path.cpp
//  NOC_6_05_PathFollowingSimple
//
//  Created by Greg Kepler on 1/1/14.
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
    mRadius = 20;
    mStart = Vec2f( 0.0, getWindowHeight() / 3 );
	mEnd = Vec2f( getWindowWidth(), 2 * getWindowHeight() / 3 );
}

void Path::display()
{	
	gl::lineWidth( mRadius * 2.0 );
	gl::color( ColorA8u( 0, 0, 0, 100 ) );
	gl::drawLine( mStart, mEnd );
	
	gl::lineWidth( 1.0 );
	gl::color( Color::black() );
	gl::drawLine( mStart, mEnd );
}
