#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include <Box2D/Box2D.h>

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_5_03_ChainShape_SimpleAppApp : public AppNative {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    b2World* mWorld;
    vector mParticles;
};

void NOC_5_03_ChainShape_SimpleAppApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 640, 360 );
}

void NOC_5_03_ChainShape_SimpleAppApp::setup()
{
    b2Vec2 gravity( 0.0f, 10.0f );
    mWorld = new b2World( gravity );
}

void NOC_5_03_ChainShape_SimpleAppApp::mouseDown( MouseEvent event )
{
}

void NOC_5_03_ChainShape_SimpleAppApp::update()
{
}

void NOC_5_03_ChainShape_SimpleAppApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( NOC_5_03_ChainShape_SimpleAppApp, RendererGl )
