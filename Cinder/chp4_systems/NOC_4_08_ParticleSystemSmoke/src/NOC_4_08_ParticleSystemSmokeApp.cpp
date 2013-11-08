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
	void drawVector( Vec2f v, Vec2f loc, float scale );
	
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

	for( int i = 0; i < 2; i++ ){
		ps.addParticle();
	}
	ps.run();
	
	// Draw an arrow representing the wind force
	drawVector( wind, Vec2f( getWindowWidth() / 2, 50 ), 500 );
}

// Renders a vector object 'v' as an arrow and a location 'loc'
void NOC_4_08_ParticleSystemSmokeApp::drawVector( Vec2f v, Vec2f loc, float scale )
{
	glPushMatrix();
	float arrowsize = 4.0;
	// Translate to location to render vector
	gl::translate( loc );
	
	gl::color( Color::white() );
	// There is no heading2d function in cinder so get direction this way (note that pointing up is a heading of 0) and rotate
	gl::rotate( toDegrees( atan2( v.y, v.x ) ) );
	
	// Calculate length of vector & scale it to be bigger or smaller if necessary
	float len = v.length() * scale;
	
	// Draw three lines to make an arrow (draw pointing up since we've rotate to the proper direction)
	gl::drawLine( Vec2f::zero(), Vec2f( len , 0.0 ) );
	gl::drawLine( Vec2f( len, 0 ), Vec2f( len - arrowsize , arrowsize / 2 ) );
	gl::drawLine( Vec2f( len, 0 ), Vec2f( len - arrowsize , -arrowsize / 2 ) );
	glPopMatrix();
}

CINDER_APP_NATIVE( NOC_4_08_ParticleSystemSmokeApp, RendererGl )
