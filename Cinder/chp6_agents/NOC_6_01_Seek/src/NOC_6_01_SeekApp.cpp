#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Vehicle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_6_01_SeekApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseMove( MouseEvent event );
	void update();
	void draw();
	
	Vehicle	*mVehicle;
	Vec2f	mMousePos;
};

void NOC_6_01_SeekApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_6_01_SeekApp::setup()
{
	mVehicle = new Vehicle( getWindowSize() / 2 );
}

void NOC_6_01_SeekApp::mouseMove( MouseEvent event )
{
	mMousePos = event.getPos();
}

void NOC_6_01_SeekApp::update()
{
	// Call the appropriate steering behaviors for our agents
	mVehicle->seek( mMousePos );
	mVehicle->update();
}

void NOC_6_01_SeekApp::draw()
{
	gl::clear( Color::white() );
	
	// Draw an ellipse at the mouse location
	gl::color( Color8u::gray( 200 ) );
	gl::drawSolidEllipse( mMousePos, 24.0, 24.0 );
	
	gl::color( Color::black() );
	gl::lineWidth( 2.0 );
	gl::drawStrokedEllipse( mMousePos, 24.0, 24.0 );
	
	mVehicle->display();
}

CINDER_APP_NATIVE( NOC_6_01_SeekApp, RendererGl )
