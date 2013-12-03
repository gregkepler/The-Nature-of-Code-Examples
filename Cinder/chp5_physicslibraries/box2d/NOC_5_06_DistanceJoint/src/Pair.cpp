//
//  Pair.cpp
//  NOC_5_06_DistanceJoint
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "Pair.h"

using namespace ci;
using namespace ci::app;
using namespace	std;

Pair::Pair( b2World* const world, ci::Vec2f pos )
{
	mLength = 32.0;
	mWorld = world;
	p1 = new Particle( world, pos );
	p2 = new Particle( world, Vec2f( pos.x + randFloat( -1.0, 1.0 ), pos.y + randFloat( -1.0, 1.0 ) ) );
	mCreated = false;
	
    // Connection between previous particle and this one
    djd.bodyA = p1->mBody;
    djd.bodyB = p2->mBody;
    // Equilibrium length
    djd.length = mLength;
	
    // These properties affect how springy the joint is
    djd.frequencyHz = 1;  // Try a value less than 5 (0 for no elasticity)
    djd.dampingRatio = 0.1; // Ranges between 0 and 1 (1 for no springiness)
}

// The joint is created seperately so ensure that it's not created while in the middle of a box2d 'step' function
// It will otherwise give you a Assertion failed: (IsLocked() == false) error
void Pair::create()
{
	if( mCreated ) return;
	// Make the joint.  Note we aren't storing a reference to the joint ourselves anywhere!
    // We might need to someday, but for now it's ok
    b2DistanceJoint* dj = (b2DistanceJoint*) mWorld->CreateJoint( &djd );
	mCreated = true;
}

void Pair::display()
{
	b2Vec2 pos1 = p1->mBody->GetPosition();
    b2Vec2 pos2 = p2->mBody->GetPosition();
	
	gl::color( Color::black() );
	gl::lineWidth( 2.0 );
	gl::drawLine( Vec2f( pos1.x, pos1.y ), Vec2f( pos2.x, pos2.y ) );
	
    p1->display();
    p2->display();
}