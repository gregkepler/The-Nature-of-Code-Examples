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
	
	float		mWeight;			// Connection has a weight
	float		mOutput;			// Need to store the output for when its time to pass along
	
	// Variables to track the animation
	bool		mSending;
	ci::Vec2f	mSender;
	
public:
	Connection( Neuron* from, Neuron* to, float w );
	void feedforward( float val );
	void update();
	void display();
};

#endif