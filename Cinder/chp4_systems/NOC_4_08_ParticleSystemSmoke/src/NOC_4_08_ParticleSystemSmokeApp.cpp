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
	void update();
	void draw();
	
	ParticleSystem ps;
};

void NOC_4_08_ParticleSystemSmokeApp::prepareSettings( Settings *settings )
{
	FILE* f;
	
	const char* gFile = "texture.png";
	
	string pathToFile = getAssetPath(fs::path( gFile )).string();
	if(fs::exists(pathToFile))
	{
		
		console() << "File Exists" << std::endl;
		f = fopen(pathToFile.c_str(), "r");
		
	}else{
		
		console() << "File aint there buddy!" << std::endl;
	}
	/*
	DataSourceRef dataSourceAsset = loadAsset("texture.png");
	fs::path pathToFile = getAssetPath("texture.png");
	
	if(fs::exists(pathToFile)) {
		console() << "File Exists = " << pathToFile << std::endl;
	} else {
		console() << "Cannot find file." << std::endl;
	}
	
	gl::Texture mImage = gl::Texture(loadImage(dataSourceAsset));
	
	/*try{
		gl::Texture img = gl::Texture( loadImage( loadAsset( "texture.png" ) ) );
	}catch( Exception e )
	{
		console() << e.what() << endl;
	}*/
	settings->setWindowSize( 640, 360 );
}

void NOC_4_08_ParticleSystemSmokeApp::setup()
{

	ps = ParticleSystem( Vec2f( getWindowWidth() / 2, 50.0 ) );
}

void NOC_4_08_ParticleSystemSmokeApp::update()
{
}

void NOC_4_08_ParticleSystemSmokeApp::draw()
{
	gl::clear( Color::white() );
	
	Vec2f gravity = Vec2f( 0, 0.1 );
	ps.applyForce( gravity );
	ps.addParticle();
	ps.run();
}

CINDER_APP_NATIVE( NOC_4_08_ParticleSystemSmokeApp, RendererGl )
