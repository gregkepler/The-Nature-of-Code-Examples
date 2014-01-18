//
//  KochLine.cpp
//
//  Created by Greg Kepler
//
//	Koch Curve
//	A class to describe one line segment in the fractal
//	Includes methods to calculate midPVectors along the line according to the Koch algorithm
//
//

#include "cinder/app/appNative.h"
#include "KochLine.h"

using namespace ci;
using namespace ci::app;
using namespace std;


KochLine::KochLine( Vec2f a, Vec2f b )
{
	mStart = a;
	mEnd = b;
}


void KochLine::display()
{
	gl::color( Color::black() );
	gl::drawLine( mStart, mEnd );
}

Vec2f KochLine::kochA()
{
	return mStart;
}

// This is easy, just 1/3 of the way
Vec2f KochLine::kochB()
{
	Vec2f v = mEnd - mStart;
	v /= 3;
	v += mStart;
    return v;
}

// More complicated, have to use a little trig to figure out where this PVector is!
Vec2f KochLine::kochC() {
    Vec2f a = Vec2f( mStart ); // Start at the beginning
    
    Vec2f v = mEnd - mStart;
	v /= 3;
	a += v; // Move to point B
	
	v.rotate( toRadians( -60.0 ) );
	a += v;	// Move to point C
   
    return a;
}

// Easy, just 2/3 of the way
Vec2f KochLine::kochD()
{
    Vec2f v = mEnd - mStart;
	v *= 2.0 / 3.0;
	v += mStart;
    return v;
}

Vec2f KochLine::kochE()
{
    return mEnd;
}
