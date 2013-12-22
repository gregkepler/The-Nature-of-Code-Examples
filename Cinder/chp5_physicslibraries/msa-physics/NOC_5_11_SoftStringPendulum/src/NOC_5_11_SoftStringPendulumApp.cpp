//
//  Example 5-11: Soft String Pedulum
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  A soft pendulum (series of connected springs)<
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "MSAPhysics2D.h"
#include "Chain.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_5_11_SoftStringPendulumApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
	void mouseDrag( MouseEvent event );
	void mouseUp( MouseEvent event );
	void update();
	void draw();
	
	msa::physics::World2D		mPhysics;
	Chain*						mChain;
	Vec2f						mMousePos;
	
};

void NOC_5_11_SoftStringPendulumApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 640, 360 );
}

void NOC_5_11_SoftStringPendulumApp::setup()
{
	// Initialize the physics world
	mPhysics.setGravity( Vec2f(0, 0.1) );
	mPhysics.setWorldSize( Vec2f::zero(), getWindowSize() );
	
	// Initialize the chain
	mChain = new Chain( &mPhysics, 180, 20, 16, 0.2);
}

void NOC_5_11_SoftStringPendulumApp::mouseDown( MouseEvent event )
{
	// Check to see if we're grabbing the chain
	mChain->contains( event.getPos() );
	mMousePos = event.getPos();
}

void NOC_5_11_SoftStringPendulumApp::mouseDrag( MouseEvent event )
{
	mMousePos = event.getPos();
}

void NOC_5_11_SoftStringPendulumApp::mouseUp( MouseEvent event )
{
	// Release the chain
	mChain->release();
}

void NOC_5_11_SoftStringPendulumApp::update()
{
	// Update physics
	mPhysics.update();
}

void NOC_5_11_SoftStringPendulumApp::draw()
{
	gl::clear( Color::white() );
	
	// Update chain's tail according to mouse location
	mChain->updateTail( mMousePos );
	// Display chain
	mChain->display();
}

CINDER_APP_NATIVE( NOC_5_11_SoftStringPendulumApp, RendererGl )
