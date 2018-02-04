//
//  Attractor.h
//  NOC_2_7_attraction_many
//
//  Created by Greg Kepler on 11/22/12.
//
//

#pragma once

#include "Mover.h"

class Attractor {
public:
	Attractor();
	Attractor( ci::vec2 loc );
	ci::vec2 attract( const Mover &m );
	void display();
	
	float		mMass;			// Mass, tied to size
	float		mGravity;		// Gravitational Constant
	ci::vec2	mLocation;		// Location
};
