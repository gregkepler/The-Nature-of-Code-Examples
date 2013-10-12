//
//  Example 4-2: ArrayList Particles
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_4_02_ArrayListParticlesApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	ArrayList<Particle> particles;
};

void NOC_4_02_ArrayListParticlesApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}


void NOC_4_02_ArrayListParticlesApp::setup()
{
	particles = new ArrayList<Particle>();
}

void NOC_4_02_ArrayListParticlesApp::mouseDown( MouseEvent event )
{
}

void NOC_4_02_ArrayListParticlesApp::update()
{
}

void NOC_4_02_ArrayListParticlesApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( NOC_4_02_ArrayListParticlesApp, RendererGl )
