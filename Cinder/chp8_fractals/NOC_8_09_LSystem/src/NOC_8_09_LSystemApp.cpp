//
//  Example 8-8: L-System
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Rule.h"
#include "LSystem.h"
#include "Turtle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_8_09_LSystemApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	LSystem *lsys;
	Turtle	*turtle;
	bool	redraw, firstDraw;
	int		counter;
	
};

void NOC_8_09_LSystemApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 600, 600 );
}

void NOC_8_09_LSystemApp::setup()
{
	/*
	// Create an empty ruleset
	vector<Rule*> ruleset;
	// Fill with two rules (These are rules for the Sierpinksi Gasket Triangle)
	ruleset.push_back( new Rule( 'F', "F--F--F--G" ) );
	ruleset.push_back( new Rule( 'G',"GG") );
	 // Create LSystem with axiom and ruleset
	lsys = new LSystem( "F--F--F", &ruleset );
	turtle = new Turtle( lsys->getSentence(), getWindowWidth() * 2, toDegrees( (M_PI*2) / 3 ) );
	 */
	
	/*
	vector<Rule*> ruleset;
//	ruleset.push_back( new Rule( 'F', "F[F]-F+F[--F]+F-F" ) );
	ruleset.push_back( new Rule( 'F', "FF+[+F-F-F]-[-F+F+F]" ) );
	lsys = new LSystem( "F-F-F-F", &ruleset );
	turtle = new Turtle( lsys->getSentence(), getWindowWidth() - 1, toDegrees( M_PI/2 ) );
	*/
	
	vector<Rule*> ruleset;
	ruleset.push_back( new Rule( 'F', "FF+[+F-F-F]-[-F+F+F]" ) );
	lsys = new LSystem( "F", &ruleset );
	turtle = new Turtle( lsys->getSentence(), getWindowHeight() / 3, 25.0 );
	
	redraw = true;
	counter = 0;
	firstDraw = true;
}

void NOC_8_09_LSystemApp::mouseDown( MouseEvent event )
{
	if (counter < 5) {
		lsys->generate();
		turtle->setToDo( lsys->getSentence() );
		turtle->changeLen( 0.5 );
		counter++;
		redraw = true;
	}
	
}

void NOC_8_09_LSystemApp::update()
{
}

void NOC_8_09_LSystemApp::draw()
{
	// only fill the background on the first draw
	if(firstDraw)
	{
		gl::clear( Color::white() );
		firstDraw = false;
	}
	
	if( redraw )
	{
		gl::pushMatrices();
		gl::translate( getWindowWidth() / 2, getWindowHeight() );
		gl::rotate( toDegrees( -M_PI / 2 ) );
		turtle->render();
		gl::popMatrices();
		redraw = false;
	}
}

CINDER_APP_NATIVE( NOC_8_09_LSystemApp, RendererGl )
