//
//  Example 6-5: Path Following Simple
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//	Wolfram Cellular Automata
//
//	Simple demonstration of a Wolfram 1-dimensional cellular automata
//	When the system reaches bottom of the window, it restarts with a new ruleset
//	Mouse click restarts as well
//
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/Utilities.h"
#include "CA.h"

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/ImageIo.h"
#include "cinder/Utilities.h"

#include <sstream>
#include <list>

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_7_01_WolframCA_figuresApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	CA *ca;
};

void NOC_7_01_WolframCA_figuresApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 1200, 600 );
}

void NOC_7_01_WolframCA_figuresApp::setup()
{
	vector<int> ruleset = {0,1,0,1,1,0,1,0};    // 90
//	vector<int> ruleset = {0,1,1,1,1,0,1,1};    // An initial rule system
	
	ca = new CA( ruleset );
}

void NOC_7_01_WolframCA_figuresApp::mouseDown( MouseEvent event )
{
	gl::clear( Color::white() );
	ca->randomize();
	ca->restart();
}

void NOC_7_01_WolframCA_figuresApp::update()
{
}

void NOC_7_01_WolframCA_figuresApp::draw()
{
	ca->render();    // Draw the CA
	ca->generate();  // Generate the next level
	
	if( ca->finished() ) {   // If we're done, clear the screen, pick a new ruleset and restart
		ci::writeImage("rule222.png", copyWindowSurface() );
	}
}

CINDER_APP_NATIVE( NOC_7_01_WolframCA_figuresApp, RendererGl )
