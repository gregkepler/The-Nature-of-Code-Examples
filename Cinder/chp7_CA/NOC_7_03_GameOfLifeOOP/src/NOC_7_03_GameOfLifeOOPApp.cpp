//
//  Example 7-3: Game of Life OOP
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//	A basic implementation of John Conway's Game of Life CA
//
//	Each cell is now an object!
//
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "GOL.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_7_03_GameOfLifeOOPApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	GOL	*gol;
};

void NOC_7_03_GameOfLifeOOPApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
	settings->setFrameRate( 24 );
}

void NOC_7_03_GameOfLifeOOPApp::setup()
{
	gol = new GOL();
}

void NOC_7_03_GameOfLifeOOPApp::mouseDown( MouseEvent event )
{
	gol->init();
}

void NOC_7_03_GameOfLifeOOPApp::update()
{
}

void NOC_7_03_GameOfLifeOOPApp::draw()
{
	// clear out the window with black
	gl::clear( Color::white() );
	
	gol->generate();
	gol->display();
}

CINDER_APP_NATIVE( NOC_7_03_GameOfLifeOOPApp, RendererGl )
