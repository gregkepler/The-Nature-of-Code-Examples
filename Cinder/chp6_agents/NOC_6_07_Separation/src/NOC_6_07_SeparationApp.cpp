//
//  Example 6-7: Separation
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//	Separation
//	Via Reynolds: http://www.red3d.com/cwr/steer/
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/Text.h"
#include "cinder/gl/Texture.h"
#include "Vehicle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_6_07_SeparationApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDrag( MouseEvent event );
	void update();
	void draw();
	
	// A list of vehicles
	vector<Vehicle*>	mVehicles;
};

void NOC_6_07_SeparationApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_6_07_SeparationApp::setup()
{
	// We are now making random vehicles and storing them in a vector
	for (int i = 0; i < 100; i++) {
		mVehicles.push_back( new Vehicle( Vec2f( randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) ) ) );
	}
}

void NOC_6_07_SeparationApp::mouseDrag( MouseEvent event )
{
	console() << event.getPos() << endl;
	mVehicles.push_back( new Vehicle( event.getPos() ) );
}

void NOC_6_07_SeparationApp::update()
{
}

void NOC_6_07_SeparationApp::draw()
{
	gl::clear( Color::white() );
	
	for( Vehicle *v : mVehicles) {
		// Path following and separation are worked on in this function
		v->separate( &mVehicles );
		// Call the generic run method (update, borders, display, etc.)
		v->update();
		v->borders();
		v->display();
	}
	
	// Instructions
	gl::enableAlphaBlending();
	gl::color( Color::black() );
	TextBox tbox = TextBox().size( Vec2i( getWindowWidth(), TextBox::GROW ) ).text( "Drag the mouse to generate new vehicles." );
	tbox.setBackgroundColor( ColorA( 0, 0, 0, 0 ) );
	glPushMatrix();
	gl::translate( Vec2f( 10.0, getWindowHeight() - 30.0 ) );
	gl::draw(  gl::Texture( tbox.render() ) );
	glPopMatrix();
}

CINDER_APP_NATIVE( NOC_6_07_SeparationApp, RendererGl )
