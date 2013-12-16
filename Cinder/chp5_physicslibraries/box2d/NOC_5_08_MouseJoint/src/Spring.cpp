//
//  Spring.cpp
//  NOC_5_08_MouseJoint
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/Gl.h"
#include "Spring.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Spring::Spring( b2World* const world )
{
	mWorld = world;
}

// If it exists we set its target to the mouse location
void Spring::update(float x, float y)
{
	if( mMouseJoint ) {
		// Always convert to world coordinates!
		b2Vec2 mouseWorld = b2Vec2( x, y );
		mMouseJoint->SetTarget( mouseWorld );
    }
}

void Spring::display()
{
    if( mMouseJoint ) {
		// We can get the two anchor points
//		b2Vec2 v1 = b2Vec2( 0, 0 );
		b2Vec2 v1 = mMouseJoint->GetAnchorA();

//		b2Vec2 v2 = b2Vec2( 0, 0 );
		b2Vec2 v2 = mMouseJoint->GetAnchorB();
		// Convert them to screen coordinates
//		v1 = box2d.coordWorldToPixels(v1);
//		v2 = box2d.coordWorldToPixels(v2);
		// And just draw a line
//		stroke(0);
//		strokeWeight(1);
//		glL:
		
		gl::drawLine( Vec2f( v1.x, v1.y), Vec2f( v2.x, v2.y ) );
    }
}

// This is the key function where
// we attach the spring to an x,y location
// and the Box object's location
void Spring::bind( float x, float y, Box* const box ) {
    // Define the joint
    b2MouseJointDef md;
	
	b2BodyDef bd;
	md.bodyA = mWorld->CreateBody(&bd);
	
    // Body A is just a fake ground body for simplicity (there isn't anything at the mouse)
//    md.bodyA = mWorld->GetGroundBody();
    // Body 2 is the box's boxy
    md.bodyB = box->mBody;
    // Get the mouse location in world coordinates
    b2Vec2 mp = b2Vec2( x, y );
    // And that's the target
    md.target.Set(mp.x, mp.y);
    // Some stuff about how strong and bouncy the spring should be
    md.maxForce = 1000.0 * box->mBody->GetMass();
    md.frequencyHz = 5.0;
    md.dampingRatio = 0.9;
	
    // Make the joint!
    mMouseJoint = ( b2MouseJoint* ) mWorld->CreateJoint( &md );
}