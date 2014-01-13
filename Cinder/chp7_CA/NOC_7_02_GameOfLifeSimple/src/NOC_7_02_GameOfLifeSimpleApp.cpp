//
//  Example 7-2: Game of Life Simple
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//	A basic implementation of John Conway's Game of Life CA
//	how could this be improved to use object oriented programming?
//	think of it as similar to our particle system, with a "cell" class
//	to describe each individual cell and a "cellular automata" class
//	to describe a collection of cells
//
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "GOL.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_7_02_GameOfLifeSimpleApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	GOL	*gol;
};

void NOC_7_02_GameOfLifeSimpleApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
	settings->setFrameRate( 24 );
}

void NOC_7_02_GameOfLifeSimpleApp::setup()
{
	gol = new GOL();
}

void NOC_7_02_GameOfLifeSimpleApp::mouseDown( MouseEvent event )
{
	gol->init();
}

void NOC_7_02_GameOfLifeSimpleApp::update()
{
}

void NOC_7_02_GameOfLifeSimpleApp::draw()
{
	// clear out the window with black
	gl::clear( Color::white() );
	
	gol->generate();
	gol->display();
}

CINDER_APP_NATIVE( NOC_7_02_GameOfLifeSimpleApp, RendererGl )
