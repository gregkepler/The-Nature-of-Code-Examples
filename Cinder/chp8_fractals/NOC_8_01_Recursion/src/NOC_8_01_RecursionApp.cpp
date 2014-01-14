//
//  Example 8-1: Recusion
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//	Simple Recursion
//
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_8_01_RecursionApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	void drawCircle( Vec2f loc, float r );
};

void NOC_8_01_RecursionApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_8_01_RecursionApp::setup()
{

}

// Very simple function that draws one circle
// and recursively calls itself
void NOC_8_01_RecursionApp::drawCircle( Vec2f loc, float r )
{
	gl::color( Color::black() );
	gl::drawStrokedEllipse( loc, r, r );
	// Exit condition, stop when radius is too small
	if( r > 2 ) {
		r *= 0.75f;
		// Call the function inside the function! (recursion!)
		drawCircle( loc, r);
	}
}

void NOC_8_01_RecursionApp::update()
{
}

void NOC_8_01_RecursionApp::draw()
{
	gl::clear( Color::white() );
	
	drawCircle( Vec2f( getWindowSize() / 2 ), getWindowWidth() );
}

CINDER_APP_NATIVE( NOC_8_01_RecursionApp, RendererGl )
