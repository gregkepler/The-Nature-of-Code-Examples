//
//  Face.h
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "DNA.h"

class Face {
	
	DNA			*mDna;			// Face's DNA
	float		mFitness;		// How good is this face?
	ci::Vec2f	mLocation;      // Position on screen
	bool		mRolloverOn;	// Are we rolling over this face?
	ci::Rectf	mRect;

	
public:
	Face( DNA* dna, ci::Vec2f loc );
	~Face();
	
	void display();
	DNA* getDNA();
	float getFitness();
	void rollover( ci::Vec2f loc );
	
};