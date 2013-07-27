#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_3_11_springApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void NOC_3_11_springApp::setup()
{
}

void NOC_3_11_springApp::mouseDown( MouseEvent event )
{
}

void NOC_3_11_springApp::update()
{
}

void NOC_3_11_springApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( NOC_3_11_springApp, RendererGl )
