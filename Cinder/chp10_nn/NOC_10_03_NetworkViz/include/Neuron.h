//
//  Neuron.h
//  NOC_10_03_NetworkViz
//
//  Created by Greg Kepler on 3/8/14.
//
//

#ifndef NEURON_H
#define NEURON_H

class Connection;

#include "cinder/app/AppNative.h"
#include "Connection.h"

class Neuron {
	std::vector<Connection*>	mConnections;		// Neuron has a list of connections
	
public:
	Neuron( ci::Vec2i loc );
	void addConnection( Connection* c );
	void display();
	
	ci::Vec2f					mLocation;			// Neuron has a location
	
};

#endif