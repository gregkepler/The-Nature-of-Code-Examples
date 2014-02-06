//
//  Obstacle.cpp
//  NOC_9_03_SmartRockets
//
//  Created by Greg Kepler on 2/6/14.
//
//

#include "cinder/app/AppNative.h"
#include "Obstacle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

void Obstacle::display()
{
	Rectf rect = Rectf( mLocation.x, mLocation.y, mLocation.x + mWidth, mLocation.y + mHeight );
	
	gl::color( Color8u::gray( 175 ) );
	gl::drawSolidRect( rect );
	gl::lineWidth( 2.0 );
	gl::color( Color::black() );
	gl::drawStrokedRect( rect );
}

bool Obstacle::contains( Vec2f spot )
{
    if( spot.x > mLocation.x && spot.x < mLocation.x + mWidth && spot.y > mLocation.y && spot.y < mLocation.y + mHeight ) {
		return true;
    } else {
		return false;
    }
}