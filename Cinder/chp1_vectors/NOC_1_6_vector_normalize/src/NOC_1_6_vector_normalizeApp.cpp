//
//  Example 1-6: Normalize
//  Demonstration of normalizing a vector.
//  Normalizing a vector sets its length to 1.
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//


#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_1_6_vector_normalizeApp : public AppBasic {
public:
	void prepareSettings( Settings *settings);
	void setup();
	void mouseMove( MouseEvent event );
	void update();
	void draw();
	
	Vec2f mMousePos;
};

void NOC_1_6_vector_normalizeApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_1_6_vector_normalizeApp::setup()
{
}

void NOC_1_6_vector_normalizeApp::update()
{
}

void NOC_1_6_vector_normalizeApp::mouseMove( MouseEvent event )
{
	mMousePos = event.getPos();
}

void NOC_1_6_vector_normalizeApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	
	// A vector that points to the mouse location
	Vec2f mouse = mMousePos;
	// A vector that points to the center of the window
	Vec2f center = Vec2f( getWindowWidth() / 2, getWindowHeight() / 2 );
	// Subtract center from mouse which results in a vector that points from center to mouse
	mouse -= center;
	
	// Normalize the vector
	mouse.normalize();
	
	// Multiply its length by 50
	mouse *= 150;
	
	// Need push and pop matrix since the matrix doesn't reset on draw like in processing
	glPushMatrix();
	gl::translate( getWindowWidth() / 2, getWindowHeight() / 2 );
	glLineWidth( 2.0 );
	gl::color( 0, 0, 0 );
	gl::drawLine( Vec2f( 0,0 ), Vec2f( mouse.x, mouse.y ) );
	glPopMatrix();
}

CINDER_APP_BASIC( NOC_1_6_vector_normalizeApp, RendererGl )
