//
//  Example 8-6: Tree static
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//	Recursive Tree
//	Renders a simple tree-like structure via recursion
//
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_8_06_Tree_staticApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	void branch( float len );
};

void NOC_8_06_Tree_staticApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_8_06_Tree_staticApp::setup()
{
	
}

void NOC_8_06_Tree_staticApp::update()
{
}

void NOC_8_06_Tree_staticApp::draw()
{
	gl::clear( Color::white() );
	
	gl::pushMatrices();
	// Start the tree from the bottom of the screen
	gl::translate( getWindowWidth() / 2, getWindowHeight() );
	gl::color( Color::black() );
	branch( 60 );
	gl::popMatrices();
}


void NOC_8_06_Tree_staticApp::branch( float len )
{
	gl::lineWidth( 2.0 );
	
	gl::drawLine( Vec2f( 0, 0 ), Vec2f( 0, -len ) );
	// Move to the end of that line
	gl::translate( 0, -len );
	
	len *= 0.66;
	// All recursive functions must have an exit condition!!!!
	// Here, ours is when the length of the branch is 2 pixels or less
	if( len > 2 ) {
		gl::pushMatrices();    // Save the current state of transformation (i.e. where are we now)
		gl::rotate( toDegrees( M_PI / 5.0 ) );   // Rotate by theta
		branch(len);       // Ok, now call myself to draw two new branches!!
		gl::popMatrices();     // Whenever we get back here, we "pop" in order to restore the previous matrix state
		
		// Repeat the same thing, only branch off to the "left" this time!
		gl::pushMatrices();
		gl::rotate( toDegrees( -M_PI / 5.0 ) );
		branch(len);
		gl::popMatrices();
	}
}


CINDER_APP_NATIVE( NOC_8_06_Tree_staticApp, RendererGl )