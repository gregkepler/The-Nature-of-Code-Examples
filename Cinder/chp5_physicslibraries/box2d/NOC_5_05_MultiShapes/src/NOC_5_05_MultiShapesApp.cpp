//
//  Example 5-5: MultiShapes
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Basic example of falling rectangles
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Boundary.h"
#include "Lollipop.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_5_05_MultiShapesApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	b2World*				mWorld;
	vector<Boundary*>		mBoundaries;
	vector<Lollipop*>		mLollipops;
};

void NOC_5_05_MultiShapesApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 640, 360 );
}

void NOC_5_05_MultiShapesApp::setup()
{
	b2Vec2 gravity( 0.0f, 20.0f );
    mWorld = new b2World( gravity );
	
	// Add a bunch of fixed boundaries
	int width = getWindowWidth();
	int height = getWindowHeight();
	mBoundaries.push_back( new Boundary( mWorld, Vec2f( width / 4, height - 5 ), width / 2 - 50, 10, 0 ) );
	mBoundaries.push_back( new Boundary( mWorld, Vec2f( 3 * width / 4, height - 50 ), width / 2 - 50, 10, 0 ) );
	mBoundaries.push_back( new Boundary( mWorld, Vec2f( width - 5, height / 2 ), 10, height, 0 ) );
	mBoundaries.push_back( new Boundary( mWorld, Vec2f( 5, height / 2 ), 10, height, 0 ) );
}

void NOC_5_05_MultiShapesApp::mouseDown( MouseEvent event )
{
	Lollipop *l = new Lollipop( mWorld, event.getPos() );
	mLollipops.push_back( l );
}

void NOC_5_05_MultiShapesApp::update()
{
	for( int i = 0; i < 2; ++i )
		mWorld->Step( 1 / 30.0f, 10, 10 );
}

void NOC_5_05_MultiShapesApp::draw()
{
	gl::clear( Color::white() );
	
	// Display all the boundaries
	for( auto& wall: mBoundaries ) {
		wall->display();
	}
	
	// Display all the people
	for( auto& l: mLollipops ) {
		l->display();
	}
	
	// people that leave the screen, we delete them
	// (note they have to be deleted from both the box2d world and our list
	if(mLollipops.size() > 0){
		for( vector<Lollipop*>::iterator it = mLollipops.end()-1; it != mLollipops.begin(); --it ) {
			if ((*it)->done()) {
				mLollipops.erase( it );
			}
		}
	}
}

CINDER_APP_NATIVE( NOC_5_05_MultiShapesApp, RendererGl )
