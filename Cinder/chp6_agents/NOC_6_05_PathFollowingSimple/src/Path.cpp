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
	/*strokeWeight(radius*2);
    stroke(0,100);
    line(start.x,start.y,end.x,end.y);
	
    strokeWeight(1);
    stroke(0);
    line(start.x,start.y,end.x,end.y);*/
}
