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
	ci::Rectf	mRect;			// size
	

	int			mGeneCounter;		// To count which force we're on in the genes
	bool		mHitTarget;			// Did I reach the target
	

	
public:
	Face( DNA* const dna, ci::Vec2f loc );
	~Face();
	
	void fitness();
	void display();
	DNA* getDNA();
	float getFitness();
	void rollover( ci::Vec2f loc );
	
};