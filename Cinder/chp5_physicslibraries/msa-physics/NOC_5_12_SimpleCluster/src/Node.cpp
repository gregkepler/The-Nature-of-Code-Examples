//
//  Node.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "MSAPhysics2D.h"
#include "Node.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Node::Node( Vec2f pos )
{
	mRadius = 16.0;
	moveTo( pos );
}

void Node::display()
{
	gl::color( Color8u::gray( 127 ) );
	gl::drawSolidEllipse( getPosition(), mRadius, mRadius );
	gl::color( Color::black() );
	gl::drawStrokedEllipse( getPosition(), mRadius, mRadius );
}


