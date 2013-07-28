//
//  Example 1-10: Motion 101 Acceleration
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

class NOC_1_10_motion101_accelerationApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseMove( MouseEvent event );
	void update();
	void draw();
	
	Mover *mMover;
	Vec2f mMousePos;
};

void NOC_1_10_motion101_accelerationApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_1_10_motion101_accelerationApp::setup()
{
	mMover = new Mover();
}

void NOC_1_10_motion101_accelerationApp::mouseMove( MouseEvent event )
{
	mMousePos = event.getPos();
}


void NOC_1_10_motion101_accelerationApp::update()
{
	mMover->update( mMousePos );
}

void NOC_1_10_motion101_accelerationApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	mMover->display();
}

CINDER_APP_BASIC( NOC_1_10_motion101_accelerationApp, RendererGl )
