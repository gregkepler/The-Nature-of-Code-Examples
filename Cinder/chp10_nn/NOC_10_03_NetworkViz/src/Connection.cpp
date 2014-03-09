//
//  Connection.cpp
//
//  Created by Greg Kepler
//
//

#include "Connection.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Connection::Connection( Neuron* from, Neuron* to, float w )
{
	mWeight = w;
    a = from;
    b = to;
}

// Drawn as a line
void Connection::display()
{
	gl::lineWidth( mWeight * 4.0 );
	gl::color( Color::black() );
	gl::drawLine( Vec2f( a->mLocation.x, a->mLocation.y), Vec2f( b->mLocation.x, b->mLocation.y ) );
}