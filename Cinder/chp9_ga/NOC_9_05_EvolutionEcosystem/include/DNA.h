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
	void					mutate( float m );
	
	std::vector<float>		mGenes;					// The genetic sequence
};