#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class LoadAssetApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void LoadAssetApp::setup()
{
}

void LoadAssetApp::mouseDown( MouseEvent event )
{
}

void LoadAssetApp::update()
{
}

void LoadAssetApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( LoadAssetApp, RendererGl )
