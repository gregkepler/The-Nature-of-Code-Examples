//
//  Example 4-6: Particle System Forces
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "ParticleSystem.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_4_06_ParticleSystemForcesApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	ParticleSystem ps;
};

void NOC_4_06_ParticleSystemForcesApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_4_06_ParticleSystemForcesApp::setup()
{
	ps = ParticleSystem( Vec2f( getWindowWidth() / 2, 50.0 ) );
}

void NOC_4_06_ParticleSystemForcesApp::mouseDown( MouseEvent event )
{
	
}

void NOC_4_06_ParticleSystemForcesApp::update()
{
}

void NOC_4_06_ParticleSystemForcesApp::draw()
{
	gl::clear( Color::white() );
	
	Vec2f gravity = Vec2f( 0, 0.1 );
	ps.applyForce( gravity );
	ps.addParticle();
	ps.run();
}

CINDER_APP_NATIVE( NOC_4_06_ParticleSystemForcesApp, RendererGl )
