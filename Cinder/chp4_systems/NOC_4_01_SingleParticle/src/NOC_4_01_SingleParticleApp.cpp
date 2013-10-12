#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_4_01_SingleParticleApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void NOC_4_01_SingleParticleApp::setup()
{
}

void NOC_4_01_SingleParticleApp::mouseDown( MouseEvent event )
{
}

void NOC_4_01_SingleParticleApp::update()
{
}

void NOC_4_01_SingleParticleApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( NOC_4_01_SingleParticleApp, RendererGl )
