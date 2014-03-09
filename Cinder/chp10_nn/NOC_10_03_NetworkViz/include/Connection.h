//
//  Connection.h
//
//  Created by Greg Kepler
//
//

#ifndef CONNECTION_H
#define CONNECTION_H

class Neuron;

#include "Neuron.h"

class Connection {
	
	// Connection is from Neuron A to B
	Neuron* a;
	Neuron* b;
	
	// Connection has a weight
	float mWeight;
	
public:
	Connection( Neuron* from, Neuron* to, float w );
	void display();
};

#endif