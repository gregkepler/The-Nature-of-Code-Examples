#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include <Box2d/Box2D.h>
#include "Boundary.h"
#include "CustomShape.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_5_04_PolygonsApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	b2World*				mWorld;
	vector<Boundary*>		mBoundaries;
	vector<CustomShape*>	mPolygons;
};

void NOC_5_04_PolygonsApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 640, 360 );
}

void NOC_5_04_PolygonsApp::setup()
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

void NOC_5_04_PolygonsApp::mouseDown( MouseEvent event )
{
	console() << event.getPos() << endl;
	
	mPolygons.push_back( new CustomShape( mWorld, Vec2f( event.getPos().x, event.getPos().y ) ) );
}

void NOC_5_04_PolygonsApp::update()
{
	for( int i = 0; i < 5; ++i )
		mWorld->Step( 1 / 30.0f, 10, 10 );
}

void NOC_5_04_PolygonsApp::draw()
{
	gl::clear( Color::white() );
	
	// Display all the boundaries
	for( auto& wall: mBoundaries ) {
		wall->display();
	}
	
	// Display all the people
	for( auto& cs: mPolygons ) {
		cs->display();
	}
	
	// people that leave the screen, we delete them
	// (note they have to be deleted from both the box2d world and our list
	if(mPolygons.size() > 0){
		for( vector<CustomShape*>::iterator p = mPolygons.end()-1; p != mPolygons.begin(); --p ) {
			if ((*p)->done()) {
				mPolygons.erase( p );
			}
		}
	}
	
}

CINDER_APP_NATIVE( NOC_5_04_PolygonsApp, RendererGl )
