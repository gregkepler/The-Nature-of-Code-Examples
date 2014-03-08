//
//  Network.h
//  NOC_10_03_NetworkViz
//
//  Created by Greg Kepler on 3/8/14.
//
//

#include "cinder/app/AppNative.h"
#include "Neuron.h"

class Network {
	ci::Vec2i				mLocation;
	std::vector<Neuron*>	mNeurons;
	
public:
	Network( ci::Vec2i loc );
	void connect( Neuron* a, Neuron* b );
	void addNeuron( Neuron* n );
	void display();
};