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
	
	float					mFitness;
	// The maximum strength of the forces
	float					mMaxforce;
	
	DNA*					crossover( DNA* const partner );
	void					mutate( float m );
	
	std::vector<ci::Vec2f>	mGenes;		// The genetic sequence
};