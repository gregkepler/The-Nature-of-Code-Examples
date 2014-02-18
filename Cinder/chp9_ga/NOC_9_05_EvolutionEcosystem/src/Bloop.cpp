//
//  Bloop.cpp
//  NOC_9_05_EvolutionEcosystem
//
//  Created by Greg Kepler on 2/18/14.
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "Bloop.h"

using namespace ci;
using namespace ci::app;
using namespace std;

// Create a "bloop" creature
Bloop::Bloop( Vec2f l, DNA *dna ) {
    mLocation = l;
    mHealth = 200.0;
    mXoff = randFloat( 1000.0 );
    mYoff = randFloat( 1000.0 );
    mDna = dna;
    // Gene 0 determines maxspeed and r
    // The bigger the bloop, the slower it is
    mMaxspeed = lmap( mDna->mGenes[0], 0.0f, 1.0f, 15.0f, 0.0f );
    mRadius = lmap( mDna->mGenes[0], 0.0f, 1.0f, 0.0f, 50.0f );
	mNoise = Perlin();
}

void Bloop::run()
{
	update();
    borders();
    display();
}

// A bloop can find food and eat it
void Bloop::eat( Food* f )
{
	vector<Vec2f> *food = f->getFood();
    // Are we touching any food objects?
    for (int i = food->size()-1; i >= 0; i--) {
		Vec2f foodLocation = (*food)[i];
		float d = mLocation.distance( foodLocation );
		// If we are, juice up our strength!
		if( d < mRadius / 2 ) {
			mHealth += 100.0;
			food->erase( food->begin() + i );
		}
    }
}

// At any moment there is a teeny, tiny chance a bloop will reproduce
Bloop* Bloop::reproduce()
{
	// asexual reproduction
    if( randFloat() < 0.0005 )
	{
		// Child is exact copy of single parent
		DNA *childDNA = new DNA( *mDna );
		// Child DNA can mutate
		childDNA->mutate(0.01);
		return new Bloop( mLocation, childDNA );
    }
    else {
		return 0;
    }

}

// Method to update location
void Bloop::update()
{
    // Simple movement based on perlin noise
    float vx = lmap( mNoise.noise( mXoff ), -0.5f, 0.5f, -mMaxspeed, mMaxspeed );
    float vy = lmap( mNoise.noise( mYoff ), -0.5f, 0.5f, -mMaxspeed, mMaxspeed );
	Vec2f velocity = Vec2f( vx, vy );
    mXoff += 0.01;
    mYoff += 0.01;
	
    mLocation += velocity;
    // Death always looming
    mHealth -= 0.2;
}

// Wraparound
void Bloop::borders()
{
    int width = getWindowWidth();
	int height = getWindowHeight();
	float r = mRadius;
    if( mLocation.x < -r ) mLocation.x = width + r;
    if( mLocation.y < -r ) mLocation.y = height + r;
    if( mLocation.x > width + r ) mLocation.x = -r;
    if( mLocation.y > height + r ) mLocation.y = -r;
}

// Method to display
void Bloop::display()
{
	gl::color( ColorA( 0, 0, 0, mHealth / 100.0 ) );
	gl::drawSolidEllipse( mLocation, mRadius / 2.0, mRadius / 2.0 );
	gl::drawStrokedEllipse( mLocation, mRadius / 2.0, mRadius / 2.0 );
}

// Death
bool Bloop::dead()
{
    if( mHealth < 0.0 ) {
		return true;
    }
    else {
		return false;
    }
}