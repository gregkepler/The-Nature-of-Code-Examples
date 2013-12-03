//
//  Example 5-6: Distant Joint
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Example demonstrating distance joints
//  A bridge is formed by connected a series of particles with joints
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include <Box2d/Box2D.h>
#include "Boundary.h"
#include "Pair.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_5_06_DistanceJointApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	b2World*				mWorld;
	vector<Boundary*>		mBoundaries;
	vector<Pair*>			mPairs;
};

void NOC_5_06_DistanceJointApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 640, 360 );
}

void NOC_5_06_DistanceJointApp::setup()
{
	b2Vec2 gravity( 0.0f, 10.0f );
    mWorld = new b2World( gravity );
	
	// Add a bunch of fixed boundaries
	int width = getWindowWidth();
	int height = getWindowHeight();
	mBoundaries.push_back( new Boundary( mWorld, Vec2f( width / 4, height - 5 ), width / 2 - 50, 10, 0 ) );
	mBoundaries.push_back( new Boundary( mWorld, Vec2f( 3 * width / 4, height - 50 ), width / 2 - 50, 10, 0 ) );
}

void NOC_5_06_DistanceJointApp::mouseDown( MouseEvent event )
{
	Pair *p = new Pair( mWorld, event.getPos() );
	mPairs.push_back( p );
}

void NOC_5_06_DistanceJointApp::update()
{
	for( int i = 0; i < 2; ++i )
		mWorld->Step( 1 / 30.0f, 10, 10 );
	
	for( auto& p: mPairs ) {
		p->create();
	}
}

void NOC_5_06_DistanceJointApp::draw()
{
	gl::clear( Color::white() );
	
	// Display all the boundaries
	for( auto& wall: mBoundaries ) {
		wall->display();
	}
	
	// Display all the pairs
	for( auto& p: mPairs ) {
		p->display();
	}
}

CINDER_APP_NATIVE( NOC_5_06_DistanceJointApp, RendererGl )
