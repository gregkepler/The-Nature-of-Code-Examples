//
//  Example 3-10: Pendulum Example
//  The Nature of Code
//
//  Converted from Daniel Shiffman's <http://www.shiffman.net> Processing Examples 
//  Created by Greg Kepler
//
// A simple pendulum simulation
// Given a pendulum with an angle theta (0 being the pendulum at rest) and a radius r
// we can use sine to calculate the angular component of the gravitational force.

// Gravity Force = Mass * Gravitational Constant;
// Pendulum Force = Gravity Force * sine(theta)
// Angular Acceleration = Pendulum Force / Mass = gravitational acceleration * sine(theta);

// Note this is an ideal world scenario with no tension in the
// pendulum arm, a more realistic formula might be:
// Angular Acceleration = (g / R) * sine(theta)

// For a more substantial explanation, visit:
// http://www.myphysicslab.com/pendulum1.html
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Pendulum.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_3_10_PendulumExampleApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
	void mouseUp( MouseEvent event );
	void mouseDrag( MouseEvent event );
	void update();
	void draw();
	
	Pendulum	mPendulum;
	Vec2f		mDragLoc;
};

void NOC_3_10_PendulumExampleApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_3_10_PendulumExampleApp::setup()
{
	mPendulum = Pendulum( Vec2f( getWindowWidth()/2, 0), 175 );
}

void NOC_3_10_PendulumExampleApp::mouseDown( MouseEvent event )
{
	mDragLoc = event.getPos();
	mPendulum.clicked( mDragLoc );
}

void NOC_3_10_PendulumExampleApp::mouseDrag( MouseEvent event )
{
	mDragLoc = event.getPos();
}

void NOC_3_10_PendulumExampleApp::mouseUp( MouseEvent event )
{
	mPendulum.stopDragging();
}

void NOC_3_10_PendulumExampleApp::update()
{
	mPendulum.update();
	mPendulum.drag( mDragLoc );
}

void NOC_3_10_PendulumExampleApp::draw()
{
	gl::clear( Color8u::gray( 255 ) );
	mPendulum.draw();
}

CINDER_APP_BASIC( NOC_3_10_PendulumExampleApp, RendererGl );