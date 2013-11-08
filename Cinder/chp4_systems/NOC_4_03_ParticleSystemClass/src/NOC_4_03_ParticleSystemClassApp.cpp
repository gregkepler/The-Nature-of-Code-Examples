//
//  Example 4-3: Particle System Class
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Since ArrayList doesn't exist in C++, std::vector is used instead
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "ParticleSystem.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_4_03_ParticleSystemClassApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	ParticleSystem ps;
	
};

void NOC_4_03_ParticleSystemClassApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_4_03_ParticleSystemClassApp::setup()
{
	ps = ParticleSystem( Vec2f( getWindowWidth() / 2, 50.0 ) );
}

void NOC_4_03_ParticleSystemClassApp::update()
{
}

void NOC_4_03_ParticleSystemClassApp::draw()
{
	// clear out the window with white
	gl::clear( Color::white() );
	ps.addParticle();
	ps.run();
}

CINDER_APP_NATIVE( NOC_4_03_ParticleSystemClassApp, RendererGl )
