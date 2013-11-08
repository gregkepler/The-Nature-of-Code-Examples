#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "ParticleSystem.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_4_09_AdditiveBlendingApp : public AppNative {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	ParticleSystem ps;
};

void NOC_4_09_AdditiveBlendingApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_4_09_AdditiveBlendingApp::setup()
{
	gl::Texture img = gl::Texture( loadImage( loadAsset( "texture.png" ) ) );
	ps = ParticleSystem(100,  Vec2f( getWindowWidth() / 2, 50 ), img );
}

void NOC_4_09_AdditiveBlendingApp::update()
{
}


void NOC_4_09_AdditiveBlendingApp::draw()
{
	gl::clear( Color::black() );
	
	gl::enableAdditiveBlending();
	
	for( int i = 0; i < 10; i++ ){
		ps.addParticle();
	}
	ps.run();
}

CINDER_APP_NATIVE( NOC_4_09_AdditiveBlendingApp, RendererGl )
