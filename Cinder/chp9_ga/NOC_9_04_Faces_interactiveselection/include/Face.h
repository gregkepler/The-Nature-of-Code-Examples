//
//  Face.h
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "DNA.h"

class Face {
	// All of our physics stuff
	ci::Vec2f	mLocation;
	ci::Vec2f	mVelocity;
	ci::Vec2f	mAcceleration;
	float		r;					// size
	
	// Fitness and DNA
	float		mFitness;
	DNA			*mDna;

	int			mGeneCounter;		// To count which force we're on in the genes
	bool		mHitTarget;			// Did I reach the target
	

	
public:
	Face( ci::Vec2f l, DNA* const dna );
	~Face();
	
	void fitness();
	void run();
	void applyForce( ci::Vec2f f);
	void update();
	void display();
	DNA* getDNA();
	float getFitness();
	
};