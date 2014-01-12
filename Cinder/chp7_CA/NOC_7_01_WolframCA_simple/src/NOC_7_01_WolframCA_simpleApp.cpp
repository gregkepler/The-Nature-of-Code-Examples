//
//  Example 7-1: Wolfram Cellular Automata
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//	Wolfram Cellular Automata
//
//	Simple demonstration of a Wolfram 1-dimensional cellular automata
//
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "CA.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_7_01_WolframCA_simpleApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	CA *ca;
};

void NOC_7_01_WolframCA_simpleApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 400 );
}

void NOC_7_01_WolframCA_simpleApp::setup()
{
	ca = new CA();
}

void NOC_7_01_WolframCA_simpleApp::mouseDown( MouseEvent event )
{
}

void NOC_7_01_WolframCA_simpleApp::update()
{
}

void NOC_7_01_WolframCA_simpleApp::draw()
{
	ca->display();    // Draw the CA
	if( ca->mGeneration < getWindowHeight() / ca->mWidth ) {
		ca->generate();
	}
}

CINDER_APP_NATIVE( NOC_7_01_WolframCA_simpleApp, RendererGl )
