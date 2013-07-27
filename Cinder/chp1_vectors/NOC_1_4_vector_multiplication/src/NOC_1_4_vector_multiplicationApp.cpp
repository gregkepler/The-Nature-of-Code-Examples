//
//  Example 1-4: Vector multiplication
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

class NOC_1_4_vector_multiplicationApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings);
	void setup();
	void mouseMove( MouseEvent event );
	void update();
	void draw();
	
	Vec2f mMousePos;
};

void NOC_1_4_vector_multiplicationApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_1_4_vector_multiplicationApp::setup()
{
}

void NOC_1_4_vector_multiplicationApp::update()
{
}

void NOC_1_4_vector_multiplicationApp::mouseMove( MouseEvent event )
{
	mMousePos = event.getPos();
}

void NOC_1_4_vector_multiplicationApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	
	Vec2f mouse = mMousePos;
	Vec2f center = Vec2f( getWindowWidth() / 2, getWindowHeight() / 2 );
	mouse -= center;
	
	// Multiplying a vector!  The vector is now half its original size (multiplied by 0.5).
	mouse *= 0.5;
	
	// Need push and pop matrix since the matrix doesn't reset on draw like in processing
	glPushMatrix();
	gl::translate( getWindowWidth() / 2, getWindowHeight() / 2 );
	glLineWidth( 2.0 );
	gl::color( 0, 0, 0 );
	gl::drawLine( Vec2f( 0,0 ), Vec2f( mouse.x, mouse.y ) );
	glPopMatrix();

}

CINDER_APP_BASIC( NOC_1_4_vector_multiplicationApp, RendererGl )
