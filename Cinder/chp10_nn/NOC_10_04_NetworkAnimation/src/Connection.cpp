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
	mOutput = 0;
	mSending = false;
}

// The Connection is active
void Connection::feedforward(float val)
{
    mOutput = val * mWeight;        // Compute output
    mSender = a->mLocation;			// Start animation at Neuron A
    mSending = true;				// Turn on sending
}

// Update traveling sender
void Connection::update()
{
    if( mSending )
	{
		// Use a simple interpolation
		mSender.x = lerp( mSender.x, b->mLocation.x, 0.1 );
		mSender.y = lerp( mSender.y, b->mLocation.y, 0.1 );
		float d = mSender.distance( b->mLocation );
		// If we've reached the end
		if( d < 1 )
		{
			// Pass along the output!
			b->feedforward( mOutput );
			mSending = false;
		}
    }
}

// Drawn as a line
void Connection::display()
{
	gl::lineWidth( 1.0 + mWeight * 4.0 );
	gl::color( Color::black() );
	gl::drawLine( Vec2f( a->mLocation.x, a->mLocation.y), Vec2f( b->mLocation.x, b->mLocation.y ) );
	
	if( mSending )
	{
		gl::drawSolidEllipse( mSender, 8.0, 8.0 );
    }
}