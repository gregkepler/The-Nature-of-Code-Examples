//
//  Bloop.h
//  NOC_9_05_EvolutionEcosystem
//
//  Created by Greg Kepler on 2/18/14.
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Perlin.h"
#include "DNA.h"
#include "Food.h"

class Bloop
{
public:
	Bloop( ci::Vec2f l, DNA *dna );
	void	run();
	void	update();
	void	borders();
	void	display();
	void	eat( Food* food );
	Bloop*	reproduce();
	bool	dead();
	
	ci::Vec2f	mLocation;		// Location
	DNA			*mDna;          // DNA
	float		mHealth;		// Life timer
	float		mXoff;			// For perlin noise
	float		mYoff;
	
	// DNA will determine size and maxspeed
	float		mRadius;
	float		mMaxspeed;
	
	ci::Perlin	mNoise;
	
	
};