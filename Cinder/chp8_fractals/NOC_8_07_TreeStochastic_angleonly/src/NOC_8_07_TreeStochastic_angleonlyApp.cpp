//
//  Example 8-7: Tree Stochastic - Angle Only
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Stochastic Tree
//  Renders a simple tree-like structure via recursion
//  Angles of branches are random
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

class NOC_8_07_TreeStochastic_angleonlyApp : public AppNative {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
	void update();
	void draw();
	void branch( float len );
	
	bool newTree;
};

void NOC_8_07_TreeStochastic_angleonlyApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}


void NOC_8_07_TreeStochastic_angleonlyApp::setup()
{
	newTree = true;
}

void NOC_8_07_TreeStochastic_angleonlyApp::mouseDown( MouseEvent event )
{
	newTree = true;
}

void NOC_8_07_TreeStochastic_angleonlyApp::update()
{
}


void NOC_8_07_TreeStochastic_angleonlyApp::draw()
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

void NOC_8_07_TreeStochastic_angleonlyApp::branch( float h )
{
	// thickness of the branch is mapped to its length
	float sw = lmap( h, 2.0f, 120.0f, 1.0f, 5.0f );
	glLineWidth(sw);
	float theta = randFloat( 0, M_PI / 3.0 );
	
	gl::drawLine( Vec2f( 0.0, 0.0) , Vec2f( 0.0, -h ) );
	gl::translate( 0, -h );
	
	h *= 0.66;
	if (h > 2) {
		gl::pushMatrices();
		gl::rotate( toDegrees( theta ) );
		branch( h );
		gl::popMatrices();
		gl::pushMatrices();
		gl::rotate( toDegrees( -theta ) );
		branch( h );
		gl::popMatrices();
	}
}

CINDER_APP_NATIVE( NOC_8_07_TreeStochastic_angleonlyApp, RendererGl )
