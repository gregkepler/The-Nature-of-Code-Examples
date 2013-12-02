//
//  Pair.cpp
//  NOC_5_06_DistanceJoint
//
//  Created by Greg Kepler on 12/2/13.
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
	p1 = new Particle( world, pos );
	p2 = new Particle( world, Vec2f( pos.x + randFloat( -1.0, 1.0 ), pos.y + randFloat( -1.0, 1.0 ) ) );
	
	b2DistanceJointDef djd;
    // Connection between previous particle and this one
    djd.bodyA = p1->mBody;
    djd.bodyB = p2->mBody;
    // Equilibrium length
    djd.length = mLength;
    
    // These properties affect how springy the joint is
    djd.frequencyHz = 3;  // Try a value less than 5 (0 for no elasticity)
    djd.dampingRatio = 0.1; // Ranges between 0 and 1 (1 for no springiness)
	
    // Make the joint.  Note we aren't storing a reference to the joint ourselves anywhere!
    // We might need to someday, but for now it's ok
    mWorld->CreateJoint( &djd );
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