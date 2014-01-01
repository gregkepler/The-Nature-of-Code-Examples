//
//  Example 6-5: Path Following Simple
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//	Path Following
//	Path is a just a straight line in this example
//	Via Reynolds: // http://www.red3d.com/cwr/steer/PathFollow.html
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Path.h"
#include "Vehicle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_6_05_PathFollowingSimpleApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	bool			mDebug = true;		// Using this variable to decide whether to draw all the stuff
	Path			*mPath;				// A path object (series of connected points)
	
	// Two vehicles
	Vehicle car1;
	Vehicle car2;
};

void NOC_6_05_PathFollowingSimpleApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_6_05_PathFollowingSimpleApp::setup()
{
	mPath = new Path();
	
	// Each vehicle has different maxspeed and maxforce for demo purposes
	car1 = Vehicle( Vec2f( 0.0, getWindowHeight() / 2 ), 2.0, 0.02 );
	car2 = Vehicle( Vec2f( 0.0, getWindowHeight() / 2 ), 3.0, 0.05 );
}

void NOC_6_05_PathFollowingSimpleApp::mouseDown( MouseEvent event )
{
}

void NOC_6_05_PathFollowingSimpleApp::update()
{
}

void NOC_6_05_PathFollowingSimpleApp::draw()
{
	gl::clear( Color::white() );
	
	// Display the path
	mPath->display();
	/*// The boids follow the path
	car1.follow(path);
	car2.follow(path);
	// Call the generic run method (update, borders, display, etc.)
	car1.run();
	car2.run();
	
	// Check if it gets to the end of the path since it's not a loop
	car1.borders(path);
	car2.borders(path);
	
	// Instructions
	fill(0);
	text("Hit space bar to toggle debugging lines.", 10, height-30);*/
}

CINDER_APP_NATIVE( NOC_6_05_PathFollowingSimpleApp, RendererGl )
