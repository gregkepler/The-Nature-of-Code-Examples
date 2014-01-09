//
//  Example 6-9: Flocking
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler

//	Demonstration of Craig Reynolds' "Flocking" behavior
//	See: http://www.red3d.com/cwr/
//	Rules: Cohesion, Separation, Alignment
//
//	Click mouse to add boids into the system
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Flock.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_6_09_FlockingApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	Flock	*flock;
};

void NOC_6_09_FlockingApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_6_09_FlockingApp::setup()
{
	flock = new Flock();
}

void NOC_6_09_FlockingApp::mouseDown( MouseEvent event )
{
}

void NOC_6_09_FlockingApp::update()
{
}

void NOC_6_09_FlockingApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( NOC_6_09_FlockingApp, RendererGl )
