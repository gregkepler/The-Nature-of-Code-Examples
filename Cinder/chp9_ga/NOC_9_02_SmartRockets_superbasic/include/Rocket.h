//
//  Rocket.h
//  NOC_9_02_SmartRockets_superbasic
//
//  Created by Greg Kepler on 1/29/14.
//
//

#include "cinder/app/AppNative.h"
#include "DNA.h"

class Rocket {
	// All of our physics stuff
	ci::Vec2f	mLocation;
	ci::Vec2f	mVelocity;
	ci::Vec2f	mAcceleration;
	ci::Vec2f	*mTarget;
	
	float		r;					// size
	
	// Fitness and DNA
	float		mFitness;
	DNA			*mDna;

	
	// To count which force we're on in the genes
	int			mGeneCounter;
	
	bool		mHitTarget;			// Did I reach the target
	

	
public:
	Rocket( ci::Vec2f l, DNA* const dna, ci::Vec2f* const target );
	
	void fitness();
	void run();
	void checkTarget();
	void applyForce( ci::Vec2f f);
	void update();
	void display();
	DNA* getDNA();
	float getFitness();
	
};