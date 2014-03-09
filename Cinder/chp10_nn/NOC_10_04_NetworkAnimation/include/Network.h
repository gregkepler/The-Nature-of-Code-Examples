//
//  Network.h
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "Neuron.h"

class Network {
	ci::Vec2i					mLocation;
	std::vector<Neuron*>		mNeurons;		// The Network has a list of neurons
	std::vector<Connection*>	mConnections;	// The Network now keeps a duplicate list of all Connection objects.
												// This makes it easier to draw everything in this class
	
public:
	Network( ci::Vec2i loc );
	void connect( Neuron* a, Neuron* b, float weight );
	void addNeuron( Neuron* n );
	void update();
	void feedforward(float input);
	void display();
};