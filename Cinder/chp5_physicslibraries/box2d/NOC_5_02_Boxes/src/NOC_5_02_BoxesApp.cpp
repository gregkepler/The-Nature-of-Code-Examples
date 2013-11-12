//
//  Example 5-2: Boxes
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Basic example of falling rectangles
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include <Box2D/Box2D.h>
#include "Box.h"
#include "Boundary.h"

using namespace ci;
using namespace ci::app;
using namespace std;

const float BOX_SIZE = 10;

class NOC_5_02_BoxesApp : public AppNative {
public:
    void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	b2World				*mWorld;
	vector<Box*>		mBoxes;
    vector<Boundary*>	mBoundaries;
    bool                mousePressed;
    Vec2f               mousePos;
};

void NOC_5_02_BoxesApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 640, 360 );
}

void NOC_5_02_BoxesApp::setup()
{
    // Initialize box2d physics and create the world
    // We are setting a custom gravity
	b2Vec2 gravity( 0.0f, -10.0f );
	mWorld = new b2World( gravity );
    mousePressed = false;
    
    // Add a bunch of fixed boundaries
    mBoundaries.push_back( new Boundary( mWorld, Vec2f( getWindowWidth() / 4, getWindowHeight() - 5 ), getWindowWidth() / 2 - 50, 10 ));
    mBoundaries.push_back( new Boundary( mWorld, Vec2f( 3 * ( getWindowWidth() / 4 ), getWindowHeight() - 50 ), getWindowWidth() / 2 - 50, 10 ));
}


void NOC_5_02_BoxesApp::update()
{
	// The Box2d Step function is a bit more involved in Cinder
    // We have to specify:
    // - time step
    // - velocity iterations
    // - position iterations
    
    for( int i = 0; i < 5; ++i )
		mWorld->Step( 1 / 30.0f, 10, 10 );
}

void NOC_5_02_BoxesApp::draw()
{
	gl::clear( Color::white() );
	
	// Boxes fall from the top every so often
    if (randFloat(1.0) < 0.2) {
        Box *b = new Box( mWorld, Vec2f( getWindowWidth() / 2, 30 ) );
        mBoxes.push_back( b );
    }
    
    // Display all the boundaries
    for( vector<Boundary*>::iterator wallIt = mBoundaries.begin(); wallIt != mBoundaries.end(); ++wallIt ) {
        (*wallIt)->display();
    }
    
    // Display all the boxes
    for( vector<Box*>::iterator boxIt = mBoxes.begin(); boxIt != mBoxes.end(); ++boxIt ) {
        (*boxIt)->display();
    }
    
    // Boxes that leave the screen, we delete them
    // (note they have to be deleted from both the box2d world and our list
    if(mBoxes.size() > 0){
        for( vector<Box*>::iterator boxIt = mBoxes.end()-1; boxIt != mBoxes.begin(); --boxIt ) {
            if ((*boxIt)->done()) {
                mBoxes.erase( boxIt );
            }
        }
    }
}

CINDER_APP_NATIVE( NOC_5_02_BoxesApp, RendererGl )

