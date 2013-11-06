//
//  Example 4-8: Particle System Smoke
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Smoke Particle System
//
//  A basic smoke effect using a particle system
//  Each particle is rendered as an alpha masked image
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "ParticleSystem.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_4_08_ParticleSystemSmokeApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseMove( MouseEvent e );
	void update();
	void draw();
	
	ParticleSystem ps;
	Vec2f mousePos;
};

void NOC_4_08_ParticleSystemSmokeApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_4_08_ParticleSystemSmokeApp::setup()
{
	gl::Texture img = gl::Texture( loadImage( loadAsset( "texture.png" ) ) );
	ps = ParticleSystem( Vec2f( getWindowWidth() / 2, getWindowHeight() - 75 ), img );
}

void NOC_4_08_ParticleSystemSmokeApp::update()
{
}

void NOC_4_08_ParticleSystemSmokeApp::mouseMove( MouseEvent e )
{
	mousePos = e.getPos();
}

void NOC_4_08_ParticleSystemSmokeApp::draw()
{
	gl::clear( Color::black() );
	
	// Calculate a "wind" force based on mouse horizontal position
	float dx = lmap( mousePos.x, 0.0f, float( getWindowWidth() ), -0.2f, 0.2f );
	Vec2f wind = Vec2f( dx, 0 );
	ps.applyForce(wind);
	
//	Vec2f gravity = Vec2f( 0, 0.1 );
	
//	ps.applyForce( gravity );
	ps.addParticle();
	ps.run();
}

CINDER_APP_NATIVE( NOC_4_08_ParticleSystemSmokeApp, RendererGl )
