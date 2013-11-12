//
//  Example 5-1: Box2d Exercise
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include <Box2D/Box2D.h>
#include "Box.h"

using namespace ci;
using namespace ci::app;
using namespace std;

const float BOX_SIZE = 10;

class NOC_5_01_box2d_exerciseApp : public AppNative {
public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent event );
    void mouseDrag( MouseEvent event );
	void update();
	void draw();
	
	b2World				*mWorld;
	vector<Box*>		mBoxes;
    bool                mousePressed;
    Vec2f               mousePos;
};

void NOC_5_01_box2d_exerciseApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 640, 360 );
}

void NOC_5_01_box2d_exerciseApp::setup()
{
    // In cinder, you have to set the gravity of your world in initialization
	b2Vec2 gravity( 0.0f, 10.0f );
	mWorld = new b2World( gravity );
    mousePressed = false;
}

void NOC_5_01_box2d_exerciseApp::mouseDown( MouseEvent event )
{
    mousePos = event.getPos();
    mousePressed = true;
}

void NOC_5_01_box2d_exerciseApp::mouseUp( MouseEvent event )
{
    mousePressed = false;
}

void NOC_5_01_box2d_exerciseApp::mouseDrag( MouseEvent event )
{
    mousePos = event.getPos();
}

void NOC_5_01_box2d_exerciseApp::update()
{
	// The Box2d Step function is a bit more involved in Cinder
    // We have to specify:
    // - time step
    // - velocity iterations
    // - position iterations
    
    for( int i = 0; i < 5; ++i )
		mWorld->Step( 1 / 30.0f, 10, 10 );
}

void NOC_5_01_box2d_exerciseApp::draw()
{
	gl::clear( Color::white() );
	
	// When the mouse is clicked, add a new Box object
    if (mousePressed) {
        Box *b = new Box( mWorld, mousePos );
        mBoxes.push_back( b );
    }
    
    // Display all the boxes
    for( vector<Box*>::const_iterator boxIt = mBoxes.begin(); boxIt != mBoxes.end(); ++boxIt ) {
        (*boxIt)->display();
    }
}

CINDER_APP_NATIVE( NOC_5_01_box2d_exerciseApp, RendererGl )

