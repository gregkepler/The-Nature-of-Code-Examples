//
//  MyContactListener.cpp
//  NOC_5_09_CollisionListening
//
//  Created by Greg Kepler on 12/18/13.
//
//

#include <Box2D/Box2D.h>
#include "MyContactListener.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;


MyContactListener::MyContactListener()
{
}
/*
void MyContactListener::BeginContact(b2Contact* contact) {
	
	// Collision event functions!
	// Get both fixtures
	b2Fixture *f1 = contact->GetFixtureA();
	b2Fixture *f2 = contact->GetFixtureB();
	// Get both bodies
	b2Body *b1 = f1->GetBody();
	b2Body *b2 = f2->GetBody();
	
	// Get our objects that reference these bodies
	Particle* o1 = (Particle*)b1->GetUserData();
	Particle* o2 = (Particle*)b2->GetUserData();
	
	if( o1 != NULL ){
		o1->change();
	}
	if( o2 != NULL ){
		o2->change();
	}
}
	
void MyContactListener::EndContact(b2Contact* contact)
{
		
}
*/