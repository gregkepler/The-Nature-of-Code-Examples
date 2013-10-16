//
//  Example 4-01: Single Particle
//  The Nature of Code
//
//  Converted from Daniel Shiffman's <http://www.shiffman.net> Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_4_01_SingleParticleApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Particle p;
};

void NOC_4_01_SingleParticleApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_4_01_SingleParticleApp::setup()
{
	p = Particle( Vec2f( getWindowWidth() / 2 , 20 ) );
	
}

void NOC_4_01_SingleParticleApp::update()
{
}

void NOC_4_01_SingleParticleApp::draw()
{
	// clear out the window with black
	gl::clear( Color::white() );
	
	p.run();
	if( p.isDead()) {
		p = Particle( Vec2f( getWindowWidth() / 2 , 20 ) );
	}
}

CINDER_APP_NATIVE( NOC_4_01_SingleParticleApp, RendererGl )
