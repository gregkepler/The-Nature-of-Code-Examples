//
//  Network.cpp
//  NOC_10_03_NetworkViz
//
//  Created by Greg Kepler on 3/8/14.
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
void Network::connect( Neuron* a, Neuron* b )
{
	float rand = randFloat();
    Connection *c = new Connection( a, b, rand );
    a->addConnection( c );
}

// We can draw the network
void Network::display()
{
	gl::pushMatrices();
	gl::translate( mLocation );
    for( Neuron* n : mNeurons ) {
		n->display();
    }
	gl::popMatrices();
}