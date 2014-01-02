//
//  Example 6-4: Flow Field
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//	Flow Field Following
//	Via Reynolds: http://www.red3d.com/cwr/steer/FlowFollow.html
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/Text.h"
#include "cinder/gl/Texture.h"
#include "FlowField.h"
#include "Vehicle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_6_04_FlowfieldApp : public AppNative {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
	void keyDown( KeyEvent event );
	void update();
	void draw();
	
	bool				mDebug = true;				// Using this variable to decide whether to draw all the stuff
	float				mBoundaryWidth = 25;
	FlowField			*mFlowfield;				// Flowfield object
	vector<Vehicle*>	mVehicles;					// A vector of vehicles
};

void NOC_6_04_FlowfieldApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_6_04_FlowfieldApp::setup()
{
	// Make a new flow field with "resolution" of 16
	mFlowfield = new FlowField( 20 );
	
	// Make a whole bunch of vehicles with random maxspeed and maxforce values
	for( int i = 0; i < 120; i++ ) {
		mVehicles.push_back( new Vehicle( Vec2f( randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) ), randFloat( 2.0, 5.0 ), randFloat( 0.1, 0.5 ) ) );
	}
}

void NOC_6_04_FlowfieldApp::mouseDown( MouseEvent event )
{
	mFlowfield->init();
}

void NOC_6_04_FlowfieldApp::keyDown( KeyEvent event )
{
	if( event.getChar() == ' ' )
	{
		mDebug = !mDebug;
	}
}

void NOC_6_04_FlowfieldApp::update()
{
}

void NOC_6_04_FlowfieldApp::draw()
{
	gl::clear( Color::white() );
	
	// Display the flowfield in "debug" mode
	if( mDebug ) mFlowfield->display();
	// Tell all the vehicles to follow the flow field
	for( Vehicle *v : mVehicles) {
		v->follow( mFlowfield );
		v->run();
	}
	
	// Instructions
	gl::color( Color::black() );
	TextBox tbox = TextBox().size( Vec2i( getWindowWidth(), TextBox::GROW ) ).text( "Hit space bar to toggle debugging lines.\nClick the mouse to generate a new flow field." );
	tbox.setBackgroundColor( ColorA( 0, 0, 0, 0 ) );
	gl::enableAlphaBlending();
	glPushMatrix();
	gl::translate( Vec2f( 10.0, getWindowHeight() - 30.0 ) );
	gl::draw(  gl::Texture( tbox.render() ) );
	glPopMatrix();

}

CINDER_APP_NATIVE( NOC_6_04_FlowfieldApp, RendererGl )