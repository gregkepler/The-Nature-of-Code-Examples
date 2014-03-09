//
//  Neuron.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "Neuron.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Neuron::Neuron( ci::Vec2i loc )
{
	mLocation = loc;
}

// Add a Connection
void Neuron::addConnection( Connection* c )
{
	mConnections.push_back( c );
}

// Draw Neuron as a circle
void Neuron::display()
{
	
	gl::color( Color::black() );
	gl::drawSolidEllipse( mLocation, 8.0, 8.0 );
    
    // Draw all its connections
    for( Connection *c : mConnections)
	{
		c->display();
    }
}