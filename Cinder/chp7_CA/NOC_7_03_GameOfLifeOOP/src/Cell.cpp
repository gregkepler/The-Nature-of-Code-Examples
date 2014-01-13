//
//  Cell.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "Cell.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Cell::Cell()
{
	Cell::Cell( Vec2f::zero(), 0 );
}

Cell::Cell( Vec2f loc, float w )
{
	mLoc = loc;
	mWidth = w;
	mState = randInt( 2 );
    mPrevious = mState;
}

void Cell::savePrevious()
{
    mPrevious = mState;
}

void Cell::newState(int s)
{
    mState = s;
}

void Cell::display()
{	
	if( mPrevious == 0 && mState == 1 ) gl::color( Color8u( 0, 0, 255 ) );
    else if ( mState == 1) gl::color( Color::black() );
    else if ( mPrevious == 1 && mState == 0) gl::color( Color8u( 255, 0, 0 ) );
    else gl::color( Color::white() );
	 
	glPushMatrix();
	gl::translate( mLoc );
	Rectf rect = Rectf( Vec2f::zero(), Vec2f( mWidth, mWidth ) );
	gl::drawSolidRect( rect );
	
	gl::color( Color::black() );
	gl::drawStrokedRect( rect );
	glPopMatrix();
}
