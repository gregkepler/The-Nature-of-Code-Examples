//
//  World.cpp
//  NOC_9_05_EvolutionEcosystem
//
//  Created by Greg Kepler on 2/17/14.
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "World.h"
#include "DNA.h"

using namespace ci;
using namespace ci::app;
using namespace std;

World::World( int num )
{
	// Start with initial food and creatures
    mFood = new Food( num );
//    mBloops = new ArrayList<Bloop>();              // Initialize the arraylist
    for( int i = 0; i < num; i++ )
	{
		Vec2f l = randVec2f() * Vec2f( getWindowSize() );
		DNA *dna = new DNA();
		mBloops.push_back( new Bloop( l, dna ) );
    }
}

// Make a new creature
void World::born( Vec2f loc )
{
//	Vec2f l = new PVector(x,y);
    DNA *dna = new DNA();
    mBloops.push_back( new Bloop( loc, dna ) );
}

// Run the world
void World::run()
{
	// Deal with food
    mFood->run();
    
    // Cycle through the ArrayList backwards b/c we are deleting
    for( int i = mBloops.size()-1; i >= 0; i-- )
	{
		// All bloops run and eat
		Bloop *b = mBloops[i];
		b->run();
		b->eat( mFood );
		// If it's dead, kill it and make food
		if( b->dead() )
		{
			mBloops.erase( mBloops.begin() + i );
//			mBloops.remove(i);
			mFood->add( b->mLocation );
		}
		// Perhaps this bloop would like to make a baby?
		Bloop *child = b->reproduce();
		if (child) mBloops.push_back( child );
    }
}

