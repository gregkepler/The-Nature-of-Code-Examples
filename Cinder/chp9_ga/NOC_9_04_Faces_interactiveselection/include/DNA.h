//
//  DNA.h
//
//  Created by Greg Kepler
//
//

#pragma once

class DNA {
public:
	DNA();
	DNA*					crossover( DNA* const partner );
	void					mutate( float m );
	
	float					mFitness;
	float					mMaxforce;				// The maximum strength of the forces
	std::vector<float>		mGenes;					// The genetic sequence
};