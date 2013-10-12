//
//  Spring.cpp
//  NOC_3_11_Spring
//
//  Created by Greg Kepler on 10/7/13.
//
//

#include "cinder/app/AppBasic.h"
#include "Spring.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Spring::Spring()
{
	
}

Spring::Spring(float x, float y, int l)
{
	mAnchor = Vec2f(x, y);
	mLen = l;
}

// Calculate spring force
void Spring::connect( Bob &b ) {
    // Vector pointing from anchor to bob location
	Vec2f force = b.mLocation - mAnchor;
	
    // What is distance
    float d = force.length();
    // Stretch is difference between current distance and rest length
    float stretch = d - mLen;
	
    // Calculate force according to Hooke's Law
    // F = k * stretch
    force.normalize();
    force *= (-1 * k * stretch);
    b.applyForce(force);
}

// Constrain the distance between bob and anchor between min and max
void Spring::constrainLength( Bob &b, float minlen, float maxlen )
{
    Vec2f dir = b.mLocation - mAnchor;
    float d = dir.length();
    // Is it too short?
    if (d < minlen) {
		dir.normalize();
		dir *= minlen;
		// Reset location and stop from moving (not realistic physics)
		b.mLocation = mAnchor + dir;
		b.mVelocity *= 0;
		// Is it too long?
    }
    else if (d > maxlen) {
		dir.normalize();
		dir *= maxlen;
		// Reset location and stop from moving (not realistic physics)
		b.mLocation = mAnchor + dir;
		b.mVelocity *= 0;
    }
}

void Spring::display()
{	
	Rectf rect = Rectf( mAnchor.x - 5, mAnchor.y - 5, mAnchor.x + 5, mAnchor.y + 5 );
	
	gl::color( Color8u::gray( 175 ) );
	gl::drawSolidRect( rect );
	
	gl::color( Color::black() );
	glLineWidth( 2.0f );
	gl::drawStrokedRect( rect );
}

void Spring::displayLine( Bob &b)
{
	glLineWidth( 2.0f );
	gl::color( Color::black() );
	gl::drawLine( b.mLocation, mAnchor );
}