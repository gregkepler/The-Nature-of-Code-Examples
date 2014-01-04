//
//  Example 6-6: Path Following
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//	Path Following
//	Via Reynolds: // http://www.red3d.com/cwr/steer/PathFollow.html
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Text.h"
#include "cinder/gl/Texture.h"
#include "cinder/Rand.h"
#include "Path.h"
#include "Vehicle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_6_06_PathFollowingApp : public AppNative {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void keyDown( KeyEvent event );
	void mouseDown( MouseEvent event );
	void update();
	void draw();
	void newPath();
	
	bool			mDebug = true;		// Using this variable to decide whether to draw all the stuff
	Path			*mPath;				// A path object (series of connected points)
	
	// Two vehicles
	Vehicle *car1;
	Vehicle *car2;
};

void NOC_6_06_PathFollowingApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_6_06_PathFollowingApp::setup()
{
	// Call a function to generate new Path object
	newPath();
	
	// Each vehicle has different maxspeed and maxforce for demo purposes
	car1 = new Vehicle( Vec2f( 0.0, getWindowHeight() / 2 ), 2.0, 0.02 );
	car2 = new Vehicle( Vec2f( 0.0, getWindowHeight() / 2 ), 3.0, 0.05 );
}

void NOC_6_06_PathFollowingApp::update()
{
}

void NOC_6_06_PathFollowingApp::keyDown( KeyEvent event )
{
	if( event.getChar() == ' ' )
	{
		mDebug = !mDebug;
	}
}

void NOC_6_06_PathFollowingApp::mouseDown( MouseEvent event )
{
	newPath();
}

void NOC_6_06_PathFollowingApp::draw()
{
	gl::clear( Color::white() );
	gl::enableAlphaBlending();
	
	// Display the path
	mPath->display();
	// The boids follow the path
	car1->follow( mPath );
	car2->follow( mPath );
	// Call the generic run method (update, borders, display, etc.)
	car1->run( mDebug );
	car2->run( mDebug );
	
	// Check if it gets to the end of the path since it's not a loop
	car1->borders( mPath );
	car2->borders( mPath );
	
	// Instructions
	gl::color( Color::black() );
	TextBox tbox = TextBox().size( Vec2i( getWindowWidth(), TextBox::GROW ) ).text( "Hit space bar to toggle debugging lines." );
	tbox.setBackgroundColor( ColorA( 0, 0, 0, 0 ) );
	glPushMatrix();
	gl::translate( Vec2f( 10.0, getWindowHeight() - 30.0 ) );
	gl::draw(  gl::Texture( tbox.render() ) );
	glPopMatrix();
}

void NOC_6_06_PathFollowingApp::newPath()
{
	// A path is a series of connected points
	// A more sophisticated path might be a curve
	int width = getWindowWidth();
	int height = getWindowHeight();
	
	mPath = new Path();
	mPath->addPoint( Vec2f( -20.0, height / 2 ) );
	mPath->addPoint( Vec2f( randFloat( 0, width / 2 ), randFloat( 0, height ) ) );
	mPath->addPoint( Vec2f( randFloat( width / 2, width ), randFloat( 0, height ) ) );
	mPath->addPoint( Vec2f( width + 20, height / 2 ) );
}

CINDER_APP_NATIVE( NOC_6_06_PathFollowingApp, RendererGl )
