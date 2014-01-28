#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_9_02_SmartRockets_superbasicApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void NOC_9_02_SmartRockets_superbasicApp::setup()
{
}

void NOC_9_02_SmartRockets_superbasicApp::mouseDown( MouseEvent event )
{
}

void NOC_9_02_SmartRockets_superbasicApp::update()
{
}

void NOC_9_02_SmartRockets_superbasicApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( NOC_9_02_SmartRockets_superbasicApp, RendererGl )
