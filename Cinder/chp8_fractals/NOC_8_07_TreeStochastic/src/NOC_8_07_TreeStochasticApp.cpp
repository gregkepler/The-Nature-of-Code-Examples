//
//  Example 8-7: Tree Stochastic
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Stochastic Tree
//  Renders a simple tree-like structure via recursion
//  Angles and number of branches are random
//
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/Text.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_8_07_TreeStochasticApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void branch( float len );
	
	bool newTree;
};

void NOC_8_07_TreeStochasticApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}


void NOC_8_07_TreeStochasticApp::setup()
{
	newTree = true;
}

void NOC_8_07_TreeStochasticApp::mouseDown( MouseEvent event )
{
	newTree = true;
}

void NOC_8_07_TreeStochasticApp::update()
{
}


void NOC_8_07_TreeStochasticApp::draw()
{
	if( newTree ){
		// clear out the window with black
		gl::clear( Color::white() );
		
		gl::color( Color::black() );
		TextBox tbox = TextBox().size( Vec2i( getWindowWidth(), TextBox::GROW ) ).text( "Click mouse to generate a new tree" );
		tbox.setBackgroundColor( ColorA( 0, 0, 0, 0 ) );
		gl::enableAlphaBlending();
		gl::pushMatrices();
		gl::translate( Vec2f( 10.0, getWindowHeight() - 20.0 ) );
		gl::draw(  gl::Texture( tbox.render() ) );
		gl::popMatrices();
		
		
		gl::color( Color::black() );
		// Start the tree from the bottom of the screen
		gl::pushMatrices();
		gl::translate( getWindowWidth() / 2, getWindowHeight() );
		// Start the recursive branching!
		branch( 60 );
		gl::popMatrices();
		
		newTree = false;
	}
}

void NOC_8_07_TreeStochasticApp::branch( float h )
{
	// thickness of the branch is mapped to its length
	float sw = lmap( h, 2.0f, 120.0f, 1.0f, 10.0f );
	glLineWidth(sw);
	
	// Draw the actual branch
	gl::drawLine( Vec2f( 0.0, 0.0) , Vec2f( 0.0, -h ) );
	// Move along to end
	gl::translate( 0, -h );
	
	h *= 0.66;
	// All recursive functions must have an exit condition!!!!
	// Here, ours is when the length of the branch is 2 pixels or less
	if (h > 2) {
		// A random number of branches
		int n = randInt( 1, 4 );
		
		for (int i = 0; i < n; i++) {
			// Picking a random angle
			float theta = randFloat( -M_PI / 2, M_PI / 2 );
			gl::pushMatrices();					// Save the current state of transformation (i.e. where are we now)
			gl::rotate( toDegrees( theta ) );	// Rotate by theta
			branch( h );						// Ok, now call myself to branch again
			gl::popMatrices();					// Whenever we get back here, we "pop" in order to restore the previous matrix state
		}
	}
}

CINDER_APP_NATIVE( NOC_8_07_TreeStochasticApp, RendererGl )
