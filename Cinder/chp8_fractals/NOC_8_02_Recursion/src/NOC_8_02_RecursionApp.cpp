//
//  Example 8-2: Recusion
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

class NOC_8_02_RecursionApp : public AppNative {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	void drawCircle( Vec2f loc, float r );
};

void NOC_8_02_RecursionApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_8_02_RecursionApp::setup()
{
	
}

// Very simple function that draws one circle
// and recursively calls itself
void NOC_8_02_RecursionApp::drawCircle( Vec2f loc, float r )
{
	gl::color( Color::black() );
	gl::drawStrokedEllipse( loc, r, r );
	// Exit condition, stop when radius is too small
	if( r > 2 )
	{
		// Now we draw two more circles, one to the left
		// and one to the right
		drawCircle( Vec2f( loc.x + (r), loc.y ), r / 2 );
		drawCircle( Vec2f( loc.x - (r), loc.y), r / 2 );
	}
}

void NOC_8_02_RecursionApp::update()
{
}

void NOC_8_02_RecursionApp::draw()
{
	gl::clear( Color::white() );
	
	drawCircle( Vec2f( getWindowSize() / 2 ), 200 );
}

CINDER_APP_NATIVE( NOC_8_02_RecursionApp, RendererGl )
