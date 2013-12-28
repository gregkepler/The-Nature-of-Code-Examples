//
//  Example 6-3: Stay Within Walls
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Stay Within Walls
//  "Made-up" Steering behavior to stay within walls
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Vehicle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_6_03_StayWithinWallsApp : public AppNative {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
	void update();
	void draw();
	
	Vehicle	*mVehicle;
	bool	mDebug = true;
	float	mBoundaryWidth = 25;
};

void NOC_6_03_StayWithinWallsApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_6_03_StayWithinWallsApp::setup()
{
	mVehicle = new Vehicle( getWindowSize() / 2 );
}

void NOC_6_03_StayWithinWallsApp::mouseDown( MouseEvent event )
{
	mDebug = !mDebug;
}

void NOC_6_03_StayWithinWallsApp::update()
{
}

void NOC_6_03_StayWithinWallsApp::draw()
{
	gl::clear( Color::white() );
	
	if( mDebug )
	{
		gl::color( Color8u::gray( 175 ) );
		gl::drawStrokedRect( Rectf( Vec2f( mBoundaryWidth, mBoundaryWidth ), Vec2f( getWindowWidth() - mBoundaryWidth, getWindowHeight() - mBoundaryWidth ) ) );
	}
	
	mVehicle->boundaries();
	mVehicle->run();
}

CINDER_APP_NATIVE( NOC_6_03_StayWithinWallsApp, RendererGl )