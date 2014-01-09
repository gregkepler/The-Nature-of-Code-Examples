//
//  Flock.cpp
//  NOC_6_09_Flocking
//
//  Created by Greg Kepler on 1/9/14.
//
//

#include "Flock.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Flock::Flock()
{
	
}

void Flock::run()
{
	for( Boid *b: mBoids )
	{
		b->run( &mBoids );
	}
}

void Flock::addBoid( Boid* const b )
{
	mBoids.push_back( b );
}