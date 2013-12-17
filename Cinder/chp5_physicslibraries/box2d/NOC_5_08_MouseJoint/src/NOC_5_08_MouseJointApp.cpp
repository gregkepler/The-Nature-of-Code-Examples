
//  Example 5-8: Mouse Joint
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Basic example of controlling an object with the mouse (by attaching a spring)
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include <Box2d/Box2D.h>
#include "Boundary.h"
#include "Box.h"
#include "Spring.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_5_08_MouseJointApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
	void mouseUp( MouseEvent event );
	void mouseDrag( MouseEvent event );
	void update();
	void draw();

	b2World*				mWorld;
	vector<Boundary*>		mBoundaries;
	// Just a single box this time
	Box*					mBox;
	
	// The Spring that will attach to the box from the mouse
	Spring*					mSpring;
	
	Vec2f					mMousePos;
};

void NOC_5_08_MouseJointApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 640, 360 );
}

void NOC_5_08_MouseJointApp::setup()
{
	// Initialize box2d physics and create the world
	b2Vec2 gravity( 0.0f, 10.0f );
    mWorld = new b2World( gravity );
	
	// Make the box
	mBox = new Box( mWorld, Vec2f( getWindowWidth() / 2, getWindowHeight() / 2 ) );
	
	// Make the spring (it doesn't really get initialized until the mouse is clicked)
	mSpring = new Spring( mWorld );
	
	// Add a bunch of fixed boundaries
	int width = getWindowWidth();
	int height = getWindowHeight();
	mBoundaries.push_back( new Boundary( mWorld, Vec2f( width / 2, height - 5 ), width, 10, 0 ) );
	mBoundaries.push_back( new Boundary( mWorld, Vec2f( width / 2, 5 ), width, 10, 0 ) );
	mBoundaries.push_back( new Boundary( mWorld, Vec2f( width - 5, height / 2 ), 10, height, 0 ) );
	mBoundaries.push_back( new Boundary( mWorld, Vec2f( 5, height / 2 ), 10, height, 0 ) );
}

void NOC_5_08_MouseJointApp::mouseDown( MouseEvent event )
{
	// Check to see if the mouse was clicked on the box
	if (mBox->contains( b2Vec2( event.getPos().x, event.getPos().y ) ) ) {
		// And if so, bind the mouse location to the box with a spring
		mSpring->bind( event.getPos().x, event.getPos().y, mBox );
		mMousePos = event.getPos();
	}
}

// When the mouse is released we're done with the spring
void NOC_5_08_MouseJointApp::mouseUp( MouseEvent event )
{
	mSpring->destroy();
}

void NOC_5_08_MouseJointApp::mouseDrag( MouseEvent event )
{
	mMousePos = event.getPos();
}

void NOC_5_08_MouseJointApp::update()
{
	for( int i = 0; i < 2; ++i )
		mWorld->Step( 1 / 30.0f, 10, 10 );
}

void NOC_5_08_MouseJointApp::draw()
{
	gl::clear( Color::white() );
	
	// Always alert the spring to the new mouse location
	if( mSpring ) mSpring->update( mMousePos.x, mMousePos.y );
	
	// Draw the boundaries
	for( auto& wall: mBoundaries ) {
		wall->display();
	}
	
	// Draw the box
	mBox->display();
	// Draw the spring (it only appears when active)
	if( mSpring ) mSpring->display();
}

CINDER_APP_NATIVE( NOC_5_08_MouseJointApp, RendererGl )
