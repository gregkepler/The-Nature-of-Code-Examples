//
//  Example 4-5: Particle System Inheritance Polymorphism
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

class NOC_4_05_ParticleSystemInheritancePolymorphismApp : public AppNative {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void draw();
	
	ParticleSystem ps;
};

void NOC_4_05_ParticleSystemInheritancePolymorphismApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_4_05_ParticleSystemInheritancePolymorphismApp::setup()
{
	ps = ParticleSystem( Vec2f( getWindowWidth() / 2, 50 ) );
}

void NOC_4_05_ParticleSystemInheritancePolymorphismApp::draw()
{
	// clear out the window with black
	gl::clear( Color::white() );
	
	ps.run();
	ps.addParticle();
}

CINDER_APP_NATIVE( NOC_4_05_ParticleSystemInheritancePolymorphismApp, RendererGl )
