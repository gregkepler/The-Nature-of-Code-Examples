//
//  Example 8-5: Koch Simple
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//	Koch Curve
//	Renders a simple fractal, the Koch snowflake
//	Each recursive level drawn in sequence
//
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "KochFractal.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_8_05_KochApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	KochFractal	*k;
};

void NOC_8_05_KochApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 250 );
	settings->setFrameRate( 1 );
}

void NOC_8_05_KochApp::setup()
{
	k = new KochFractal();
}

void NOC_8_05_KochApp::update()
{
}

void NOC_8_05_KochApp::draw()
{
	gl::clear( Color::white() );
	// Draws the snowflake!
	k->render();
	// Iterate
	k->nextLevel();
	// Let's not do it more than 5 times. . .
	if( k->getCount() > 5 ) {
		k->restart();
	}
}

CINDER_APP_NATIVE( NOC_8_05_KochApp, RendererGl )
