//
//  Example 2-6: Attraction
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Mover.h"
#include "Attractor.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_2_6_attractionApp : public App {
  public:
	void prepareSettings( Settings *settings );
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void mouseUp( MouseEvent event ) override;
	void mouseMove( MouseEvent event ) override;
	void mouseDrag( MouseEvent event ) override;
	void update() override;
	void draw() override;
	
	Mover		mMover;
	Attractor	mAttractor;
	vec2		mMousePos;
};

void prepareSettings( NOC_2_6_attractionApp::Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_2_6_attractionApp::setup()
{
	mAttractor = Attractor( vec2( getWindowWidth() / 2, getWindowHeight() / 2 ) );
}

void NOC_2_6_attractionApp::mouseDown( MouseEvent event )
{
	mMousePos = event.getPos();
	mAttractor.clicked( mMousePos );
}

void NOC_2_6_attractionApp::mouseUp( MouseEvent event)
{
	mAttractor.stopDragging();
}

void NOC_2_6_attractionApp::mouseMove( MouseEvent event )
{
	mMousePos = event.getPos();
}

void NOC_2_6_attractionApp::mouseDrag( MouseEvent event )
{
	mMousePos = event.getPos();
}

void NOC_2_6_attractionApp::update()
{
	vec2 force = mAttractor.attract( mMover );
	mMover.applyForce( force );
	mMover.update();
	
	mAttractor.drag( mMousePos );
	mAttractor.hover( mMousePos );
}

void NOC_2_6_attractionApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 1, 1, 1 ) );
	
	mAttractor.display();
	mMover.display();
}

CINDER_APP( NOC_2_6_attractionApp, RendererGl( RendererGl::Options().msaa( 16 ) ), prepareSettings )
