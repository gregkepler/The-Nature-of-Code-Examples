//
//  Example 4-4: Systems of Systems
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

class NOC_4_04_SystemofSystemsApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	vector<ParticleSystem> systems;
};

void NOC_4_04_SystemofSystemsApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_4_04_SystemofSystemsApp::setup()
{
	systems = vector<ParticleSystem>();
}

void NOC_4_04_SystemofSystemsApp::mouseDown( MouseEvent event )
{
	systems.push_back( ParticleSystem( event.getPos() ) );
}

void NOC_4_04_SystemofSystemsApp::update()
{
}

void NOC_4_04_SystemofSystemsApp::draw()
{
	// clear out the window with black
	gl::clear( Color::white() );
	
	for( vector<ParticleSystem>::iterator it = systems.begin(); it != systems.end(); ++it )
	{
		it->run();
		it->addParticle();
	}
}

CINDER_APP_NATIVE( NOC_4_04_SystemofSystemsApp, RendererGl )
