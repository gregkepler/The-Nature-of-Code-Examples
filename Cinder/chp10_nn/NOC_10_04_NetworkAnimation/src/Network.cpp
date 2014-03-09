//
//  Network.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "Network.h"
#include "Connection.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Network::Network( ci::Vec2i loc )
{
    mLocation = loc;
}

// We can add a Neuron
void Network::addNeuron( Neuron* n )
{
    mNeurons.push_back( n );
}

// We can connection two Neurons
void Network::connect( Neuron* a, Neuron* b, float weight )
{
    Connection *c = new Connection( a, b, weight );
    a->addConnection( c );
	
    // Also add the Connection here
    mConnections.push_back( c );
}

// Sending an input to the first Neuron
// We should do something better to track multiple inputs
void Network::feedforward( float input )
{
    Neuron* start = mNeurons[0];
    start->feedforward( input );
}

// Update the animation
void Network::update()
{
    for( Connection* c : mConnections ) {
		c->update();
    }
}

// We can draw the network
void Network::display()
{
	gl::pushMatrices();
	gl::translate( mLocation );
    for( Neuron* n : mNeurons ) {
		n->display();
    }
	
	for( Connection* c : mConnections ) {
		c->display();
    }
	gl::popMatrices();
}