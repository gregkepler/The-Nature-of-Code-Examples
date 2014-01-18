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
#include "KochLine.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_8_05_KochSimpleApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	vector<KochLine*>	mLines;
	void				generate();
};

void NOC_8_05_KochSimpleApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 383, 200 );
}

void NOC_8_05_KochSimpleApp::setup()
{
	Vec2f start = Vec2f( 0.0, 150.0 );
	Vec2f end   = Vec2f( getWindowWidth(), 150.0 );
	mLines.push_back( new KochLine( start, end ) );
	
	for( int i = 0; i < 5; i++ )
	{
		generate();
	}
}

void NOC_8_05_KochSimpleApp::update()
{
}

void NOC_8_05_KochSimpleApp::draw()
{
	gl::clear( Color::white() );
	
	for (KochLine *l : mLines) {
		l->display();
	}
}

void NOC_8_05_KochSimpleApp::generate()
{
	vector<KochLine*> next;	// Create emtpy list
	for (KochLine *l : mLines) {
		// Calculate 5 koch PVectors (done for us by the line object)
		Vec2f a = l->kochA();
		Vec2f b = l->kochB();
		Vec2f c = l->kochC();
		Vec2f d = l->kochD();
		Vec2f e = l->kochE();
		// Make line segments between all the PVectors and add them
		next.push_back( new KochLine( a, b ) );
		next.push_back( new KochLine( b, c ) );
		next.push_back( new KochLine( c, d ) );
		next.push_back( new KochLine( d, e ) );
	}
	mLines = next;
}

CINDER_APP_NATIVE( NOC_8_05_KochSimpleApp, RendererGl )
