//
//  Example 5-7: Revolute Joint
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Example demonstrating revolute joints
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include <Box2d/Box2D.h>

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_5_07_RevoluteJointApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	b2World*				mWorld;
};

void NOC_5_07_RevoluteJointApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 640, 360 );
}

void NOC_5_07_RevoluteJointApp::setup()
{
	b2Vec2 gravity( 0.0f, 10.0f );
    mWorld = new b2World( gravity );
	
	// Make the windmill at an x,y location
//	windmill = new Windmill(width/2,175);
}

void NOC_5_07_RevoluteJointApp::mouseDown( MouseEvent event )
{
}

void NOC_5_07_RevoluteJointApp::update()
{
}

void NOC_5_07_RevoluteJointApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( NOC_5_07_RevoluteJointApp, RendererGl )
