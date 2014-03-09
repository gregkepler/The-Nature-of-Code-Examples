//
//  Network.h
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "Neuron.h"

class Network {
	ci::Vec2i				mLocation;
	std::vector<Neuron*>	mNeurons;		 // The Network has a list of neurons
	
public:
	Network( ci::Vec2i loc );
	void connect( Neuron* a, Neuron* b );
	void addNeuron( Neuron* n );
	void display();
};