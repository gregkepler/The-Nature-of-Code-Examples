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
	~DNA();
	DNA( std::vector<float> genes );
	DNA*					crossover( const DNA* partner );
	void					mutate( float m );
	
	float					mFitness;
	std::vector<float>		mGenes;					// The genetic sequence
};