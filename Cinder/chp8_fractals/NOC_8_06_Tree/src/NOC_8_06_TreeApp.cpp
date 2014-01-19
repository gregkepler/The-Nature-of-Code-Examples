//
//  Example 8-6: Tree static
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//	Recursive Tree
//	Renders a simple tree-like structure via recursion
//	Branching angle calculated as a function of horizontal mouse location
//
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_8_06_TreeApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseMove( MouseEvent event );
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void branch( float len );
	
	float theta;
	Vec2f mousePos;
	

};

void NOC_8_06_TreeApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_8_06_TreeApp::setup()
{
	
}

void NOC_8_06_TreeApp::mouseDown( MouseEvent event )
{
}

void NOC_8_06_TreeApp::mouseMove( MouseEvent event )
{
	mousePos = event.getPos();
}

void NOC_8_06_TreeApp::update()
{
	// Let's pick an angle 0 to 90 degrees based on the mouse position
	theta = lmap( float( mousePos.x ), 0.0f, float( getWindowWidth() ), 0.0f, float( M_PI / 2.0f ) );
}

void NOC_8_06_TreeApp::draw()
{
	gl::clear( Color::white() );
	
	// Start the tree from the bottom of the screen
	gl::pushMatrices();
	gl::translate( getWindowWidth() / 2, getWindowHeight() );
	gl::color( Color::black() );
	branch( 60 );
	gl::popMatrices();
}

void NOC_8_06_TreeApp::branch(float len)
{
	// Each branch will be 2/3rds the size of the previous one
	
//	float sw = lmap( len, 2.0f, 120.0f, 1.0f, 10.0f );
//	glLineWidth(sw);
	glLineWidth( 2.0f );
	
	gl::drawLine( Vec2f( 0.0, 0.0) , Vec2f( 0.0, -len ) );
	// Move to the end of that line
	gl::translate( 0, -len );
	
	len *= 0.66;
	// All recursive functions must have an exit condition!!!!
	// Here, ours is when the length of the branch is 2 pixels or less
	if (len > 2) {
		gl::pushMatrices();    // Save the current state of transformation (i.e. where are we now)
		gl::rotate( toDegrees( theta ) );   // Rotate by theta
		branch( len );       // Ok, now call myself to draw two new branches!!
		gl::popMatrices();     // Whenever we get back here, we "pop" in order to restore the previous matrix state
		
		// Repeat the same thing, only branch off to the "left" this time!
		gl::pushMatrices();
		gl::rotate( toDegrees( -theta ) );
		branch( len );
		gl::popMatrices();
	}
}


CINDER_APP_NATIVE( NOC_8_06_TreeApp, RendererGl )
