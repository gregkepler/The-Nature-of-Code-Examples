//
//  Example 5-9: Collision Listening
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Demonstrates how to know which object was hit
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <Box2d/Box2D.h>
#include "Particle.h"
#include "Boundary.h"

using namespace ci;
using namespace ci::app;
using namespace std;

// be sure to extend b2ContactListener
class NOC_5_09_CollisionListeningApp : public AppNative, public b2ContactListener {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	// these must be virtual methods to overwrite the origin functions
	virtual void BeginContact( b2Contact *cp );
	virtual void EndContact( b2Contact *cp );
	
	b2World*				mWorld;
	vector<Particle*>		mParticles;
	Boundary*				mWall;
};

void NOC_5_09_CollisionListeningApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 640, 360 );
}

void NOC_5_09_CollisionListeningApp::setup()
{
	b2Vec2 gravity( 0.0f, 10.0f );
    mWorld = new b2World( gravity );
	mWall = new Boundary( mWorld, Vec2f( getWindowWidth() / 2, getWindowHeight() - 5 ), getWindowWidth(), 10, 0 );
	
	// Turn on collision listening!
	// Pass this as the contact listener (since it extends b2ContactListener)
	mWorld->SetContactListener( this );
}

void NOC_5_09_CollisionListeningApp::update()
{
	for( int i = 0; i < 2; ++i )
		mWorld->Step( 1 / 30.0f, 10, 10 );
}

void NOC_5_09_CollisionListeningApp::draw()
{
	gl::clear( Color::white() );
	
	if ( randFloat( 1.0 ) < 0.1) {
		float sz = randFloat( 4.0, 8.0 );
		mParticles.push_back( new Particle( mWorld, Vec2f( randFloat( getWindowWidth() ), 20.0 ), sz ) );
	}
	
	// Look at all particles
	// Draw all particles
	for( vector<Particle*>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ) {
		(*p)->display();
	}
	
	if(mParticles.size() > 0){
		for( vector<Particle*>::iterator p = mParticles.end()-1; p != mParticles.begin(); --p ) {
			if ((*p)->done()) {
				mParticles.erase( p );
			}
		}
	}
	
	mWall->display();
}

void NOC_5_09_CollisionListeningApp::BeginContact(b2Contact* contact) {
	
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

void NOC_5_09_CollisionListeningApp::EndContact(b2Contact* contact)
{
	
}

CINDER_APP_NATIVE( NOC_5_09_CollisionListeningApp, RendererGl )
