#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "ParticleSystem.h"

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
};

void NOC_4_07_ParticleSystemForcesRepellerApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_4_07_ParticleSystemForcesRepellerApp::setup()
{
	ps = ParticleSystem( Vec2f( getWindowWidth() / 2, 50.0 ) );
}

void NOC_4_07_ParticleSystemForcesRepellerApp::update()
{
}

void NOC_4_07_ParticleSystemForcesRepellerApp::draw()
{
	gl::clear( Color::white() );
	
	Vec2f gravity = Vec2f( 0, 0.1 );
	ps.applyForce( gravity );
	ps.addParticle();
	ps.run();
}

CINDER_APP_NATIVE( NOC_4_07_ParticleSystemForcesRepellerApp, RendererGl )
