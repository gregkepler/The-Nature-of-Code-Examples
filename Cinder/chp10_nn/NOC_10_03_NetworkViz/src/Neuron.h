//
//  Neuron.h
//  NOC_10_03_NetworkViz
//
//  Created by Greg Kepler on 3/8/14.
//
//

#pragma once

#include "cinder/app/AppNative.h"
#include "Connection.h"

class Neuron {
	
	
public:
	Neuron( ci::Vec2i loc );
	void addConnection( Connection* c );
};