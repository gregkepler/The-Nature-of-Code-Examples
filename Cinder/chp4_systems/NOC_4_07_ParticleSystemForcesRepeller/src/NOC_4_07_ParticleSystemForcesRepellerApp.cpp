//
//  Example 4-7: Particle System Forces Repeller
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "ParticleSystem.h"
#include "Repeller.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_4_07_ParticleSystemForcesRepellerApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();

	ParticleSystem ps;
	Repeller repeller;
};

void NOC_4_07_ParticleSystemForcesRepellerApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_4_07_ParticleSystemForcesRepellerApp::setup()
{
	ps = ParticleSystem( Vec2f( getWindowWidth() / 2, 50.0 ) );
	repeller = Repeller( Vec2f( ( getWindowWidth() / 2 - 20 ), ( getWindowHeight() / 2 ) ) );
}

void NOC_4_07_ParticleSystemForcesRepellerApp::update()
{
}

void NOC_4_07_ParticleSystemForcesRepellerApp::draw()
{
	gl::clear( Color::white() );
	ps.addParticle();
	
	Vec2f gravity = Vec2f( 0, 0.1 );
	ps.applyForce( gravity );
	ps.applyRepeller( repeller );
	
	repeller.display();
	ps.run();
}

CINDER_APP_NATIVE( NOC_4_07_ParticleSystemForcesRepellerApp, RendererGl )
