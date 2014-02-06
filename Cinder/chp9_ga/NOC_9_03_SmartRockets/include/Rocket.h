//
//  Rocket.h
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "DNA.h"
#include "Obstacle.h"

class Rocket {
	// All of our physics stuff
	ci::Vec2f	mLocation;
	ci::Vec2f	mVelocity;
	ci::Vec2f	mAcceleration;
	Obstacle	*mTarget;
	float		r;					// size

	int			mRecordDist;		// How close did it get to the target
	
	// Fitness and DNA
	float		mFitness;
	DNA			*mDna;

	int			mGeneCounter;		// To count which force we're on in the genes
	bool		mHitObstacle;		// Did I reach the target
	int			mFinishTime;

	

	
public:
	Rocket( ci::Vec2f l, DNA* const dna, Obstacle* const target );
	~Rocket();
	
	void fitness();
	void run( std::vector<Obstacle*> const os );
	void checkTarget();
	void obstacles( std::vector<Obstacle*> const os );
	void applyForce( ci::Vec2f f);
	void update();
	void display();
	DNA* getDNA();
	float getFitness();
	bool stopped();
	
	bool		mHitTarget;			// Did I reach the target
	
};