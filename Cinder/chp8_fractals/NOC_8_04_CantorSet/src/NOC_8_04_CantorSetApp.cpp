//
//  Example 8-4: Cantor Set
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//	Cantor Set
//	Renders a simple fractal, the Cantor Set
//
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_8_04_CantorSetApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	void cantor( float x, float y, float len );
};

void NOC_8_04_CantorSetApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_8_04_CantorSetApp::setup()
{
}

void NOC_8_04_CantorSetApp::update()
{
}

void NOC_8_04_CantorSetApp::cantor( float x, float y, float len ) {
	
	float h = 30;
	
	// recursive exit condition
	if (len >= 1) {
		// Draw line (as rectangle to make it easier to see)
		gl::color( Color::black() );
		gl::drawSolidRect( Rectf( x, y, x + len, y + h/3 ) );
		// Go down to next y position
		y += h;
		// Draw 2 more lines 1/3rd the length (without the middle section)
		cantor( x, y, len / 3 );
		cantor( x + len * 2/3, y, len / 3 );
	}
}

void NOC_8_04_CantorSetApp::draw()
{
	gl::clear( Color::white() );
	
	// Call the recursive function
	cantor(35, 0, 730);
}


CINDER_APP_NATIVE( NOC_8_04_CantorSetApp, RendererGl )
