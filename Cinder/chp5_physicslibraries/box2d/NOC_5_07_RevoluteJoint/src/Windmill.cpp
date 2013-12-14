//
//  Windmill.cpp
//  NOC_5_07_RevoluteJoint
//
//  Created by Greg Kepler
//
//  Class to describe a fixed spinning object


#include "Windmill.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Windmill::Windmill( b2World* const world, ci::Vec2f pos )
{
	mWorld = world;
	box1 = new Box( mWorld, Vec2f(pos.x, pos.y-20), 120, 10, false );
	box2 = new Box( mWorld, Vec2f(pos.x, pos.y), 10, 40, true );
	
	// Define joint as between two bodies
	b2RevoluteJointDef rjd;

	rjd.Initialize( box1->mBody, box2->mBody, box1->mBody->GetWorldCenter() );
	rjd.motorSpeed = - M_PI * 2;		// how fast?
    rjd.maxMotorTorque = 1000000.0;		// how powerful?
	rjd.enableMotor = false;			// is it on?
	
    // There are many other properties you can set for a Revolute joint
    // For example, you can limit its angle between a minimum and a maximum
    // See box2d manual for more
    
	// Create the joint
    joint = (b2RevoluteJoint*) mWorld->CreateJoint( &rjd );
}

// Turn the motor on or off
void Windmill::toggleMotor()
{
    joint->EnableMotor( !joint->IsMotorEnabled() );
}

bool Windmill::motorOn()
{
    return joint->IsMotorEnabled();
}

void Windmill::display()
{
	
    box2->display();
    box1->display();
	
    // Draw anchor just for debug
    b2Vec2 anchor = box1->mBody->GetWorldCenter();
	gl::color( Color::black() );
	gl::drawSolidEllipse( Vec2f( anchor.x, anchor.y ), 8.0, 8.0 );
}