//
//  Example 3-11: Spring Example
//  The Nature of Code
//
//  Converted from Daniel Shiffman's <http://www.shiffman.net> Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Text.h"
#include "cinder/gl/Texture.h"
#include "Spring.h"
#include "Bob.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_3_11_springApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
	void mouseUp( MouseEvent event );
	void mouseDrag( MouseEvent event );
	void update();
	void draw();
	
	Vec2f mousePos;
	Bob mBob;
	Spring mSpring;
};

void NOC_3_11_springApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_3_11_springApp::setup()
{
	// Create objects at starting location
	// Note third argument in Spring constructor is "rest length"
	mSpring = Spring( getWindowWidth() / 2, 10, 100 );
	mBob = Bob( getWindowWidth() / 2, 100 );
}

// For mouse interaction with bob
void NOC_3_11_springApp::mouseDown( MouseEvent event )
{
	mousePos = Vec2f( event.getPos() );
	mBob.clicked( mousePos );
}

void NOC_3_11_springApp::mouseUp( MouseEvent event)
{
	mBob.stopDragging();
}

void NOC_3_11_springApp::mouseDrag( MouseEvent event)
{
	mousePos = Vec2f( event.getPos() );
}

void NOC_3_11_springApp::update()
{
}

void NOC_3_11_springApp::draw()
{
	// clear out the window with black
	gl::clear( Color::gray( 255 ) );
	
	// enable alpha blending so that the text box background color will be transparent (instead of a solid white or black box)
	gl::enableAlphaBlending();
	
	// Apply a gravity force to the bob
	Vec2f gravity = Vec2f( 0.0 ,2.0 );
	mBob.applyForce( gravity );
	
	// Connect the bob to the spring (this calculates the force)
	mSpring.connect( mBob );
	// Constrain spring distance between min and max
	mSpring.constrainLength( mBob, 30, 200 );
	
	// Update bob
	mBob.update();
	// If it's being dragged
	mBob.drag( mousePos );
	
	// Draw everything
	mSpring.displayLine( mBob ); // Draw a line between spring and bob
	mBob.display();
	mSpring.display();
	
	gl::color( Color::white() );
	TextBox tbox = TextBox().alignment( TextBox::LEFT ).size( Vec2i( getWindowWidth(), TextBox::GROW ) ).text( "click on bob to drag" );
	tbox.setColor( Color::black() );
	gl::draw( gl::Texture( tbox.render() ), Vec2f( 10.0f, getWindowHeight() - tbox.measure().y - 5.0f) );
}

CINDER_APP_NATIVE( NOC_3_11_springApp, RendererGl )
