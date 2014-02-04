//
//  DNA.h
//
//  Created by Greg Kepler
//
//

#pragma once

class DNA {
public:
	DNA( int lifetime );
	DNA*					crossover( DNA* const partner );
	void					mutate( float m );
	
	float					mFitness;
	float					mMaxforce;				// The maximum strength of the forces
	std::vector<ci::Vec2f>	mGenes;					// The genetic sequence
};