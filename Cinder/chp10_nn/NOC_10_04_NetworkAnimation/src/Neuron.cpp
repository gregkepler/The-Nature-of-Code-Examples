//
//  Neuron.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "cinder/CinderMath.h"
#include "Neuron.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Neuron::Neuron( ci::Vec2i loc )
{
	mLocation = loc;
	mSum = 0;
	mRadius = 16.0;
}

// Add a Connection
void Neuron::addConnection( Connection* c )
{
	mConnections.push_back( c );
}

// Receive an input
void Neuron::feedforward( float input )
{
	// Accumulate it
    mSum += input;
    // Activate it?
    if( mSum > 1 )
	{
		fire();
		mSum = 0;  // Reset the sum to 0 if it fires
    }
}

// The Neuron fires
void Neuron::fire()
{
    mRadius = 32;   // It suddenly is bigger
    
    // We send the output through all connections
    for( Connection* c : mConnections ) {
		c->feedforward( mSum );
    }
}

// Draw Neuron as a circle
void Neuron::display()
{
	// Brightness is mapped to sum
    float b = lmap( mSum, 0.0f, 1.0f, 255.0f, 0.0f );
	gl::color( Color8u::gray( int(b) ) );
	gl::drawSolidEllipse( mLocation, mRadius, mRadius );
    
	gl::color( Color::black() );
	gl::lineWidth( 1.0 );
	gl::drawStrokedEllipse( mLocation, mRadius, mRadius );
	
	// Size shrinks down back to original dimensions
    mRadius = lerp( mRadius, 16.0f, 0.1f );

}