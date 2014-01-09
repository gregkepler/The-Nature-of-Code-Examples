//
//  Flock.cpp
//
//  Created by Greg Kepler
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