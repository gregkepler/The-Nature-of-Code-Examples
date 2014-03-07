//
//  Example 10-2: Seaking Nueral
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  A Vehicle controlled by a Perceptron
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Vehicle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_10_02_SeekingNeuralApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void mouseDown( MouseEvent event );
	void setup();
	void update();
	void draw();
	void makeTargets();
	
	Vec2f			mDesired;
	Vehicle			*mVehicle;
	vector<Vec2f>	mTargets;
};

void NOC_10_02_SeekingNeuralApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_10_02_SeekingNeuralApp::setup()
{
	// The Vehicle's desired location
	mDesired = Vec2f( getWindowCenter() );
	
	
	// Create a list of targets
	makeTargets();
	
	// Create the Vehicle (it has to know about the number of targets
	// in order to configure its brain)
	mVehicle = new Vehicle( mTargets.size(), Vec2f( randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) ), mDesired );
}

// Make a random ArrayList of targets to steer towards
void NOC_10_02_SeekingNeuralApp::makeTargets() {
	mTargets.clear();
	for (int i = 0; i < 8; i++)
	{
		mTargets.push_back( Vec2f( randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) ) );
	}
}

void NOC_10_02_SeekingNeuralApp::update()
{
}

void NOC_10_02_SeekingNeuralApp::draw()
{
	gl::clear( Color::white() );
	gl::enableAlphaBlending();
	
	// Draw a circle to show the Vehicle's goal
	gl::color( ColorA8u( 0, 0, 0, 100 ) );
	gl::drawSolidEllipse( mDesired, 18, 18);
	
	gl::color( Color::black() );
	gl::lineWidth( 2.0 );
	gl::drawStrokedEllipse( mDesired, 18, 18);
	
	// Draw the targets
	for( Vec2f target : mTargets ) {
		
		gl::color( Color::black() );
		gl::lineWidth( 2.0 );
		gl::drawStrokedEllipse( target, 8.0, 8.0 );
		gl::drawLine( Vec2f( target.x, target.y - 16.0 ), Vec2f( target.x, target.y + 16.0 ) );
		gl::drawLine( Vec2f( target.x - 16.0, target.y ), Vec2f( target.x + 16.0, target.y ) );
	}
	
	// Update the Vehicle
	mVehicle->steer( mTargets );
	mVehicle->update();
	mVehicle->display();
}

void NOC_10_02_SeekingNeuralApp::mouseDown( MouseEvent event )
{
	makeTargets();
}

CINDER_APP_NATIVE( NOC_10_02_SeekingNeuralApp, RendererGl )
