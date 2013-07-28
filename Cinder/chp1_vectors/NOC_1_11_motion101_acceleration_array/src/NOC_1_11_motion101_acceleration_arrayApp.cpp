//
//  Example 1-11: Motion 101 Acceleration with and an Array
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Acceleration with Vectors
//  Demonstration of the basics of motion with vector.
//  A "Mover" object stores location, velocity, and acceleration as vectors
//  The motion is controlled by affecting the acceleration (in this case towards the mouse)
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_1_11_motion101_acceleration_arrayApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseMove( MouseEvent event );
	void update();
	void draw();
	
	vector<Mover> mMovers;	// using a vector instead of an array
	int mMoverAmt = 20;
	Vec2f mMousePos;
};

void NOC_1_11_motion101_acceleration_arrayApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_1_11_motion101_acceleration_arrayApp::setup()
{
	mMovers.resize( mMoverAmt );
	for( int i = 0; i < mMovers.size(); i++ ){
		 mMovers[i] = Mover();
	}
}

void NOC_1_11_motion101_acceleration_arrayApp::mouseMove( MouseEvent event )
{
	mMousePos = event.getPos();
}


void NOC_1_11_motion101_acceleration_arrayApp::update()
{
	for( int i = 0; i < mMovers.size(); i++ ) {
		mMovers[i].update( mMousePos );
	}
}

void NOC_1_11_motion101_acceleration_arrayApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	for( int i = 0; i < mMoverAmt; i++ ) {
		mMovers[i].display();
	}
}

CINDER_APP_BASIC( NOC_1_11_motion101_acceleration_arrayApp, RendererGl )
