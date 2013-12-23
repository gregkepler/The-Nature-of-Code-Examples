//
//  Example 5-12: Simple Cluster
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Force directed graph,
//  heavily based on: http://code.google.com/p/fidgen/
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Text.h"
#include "cinder/gl/Texture.h"
#include "MSAPhysics2D.h"
#include "Cluster.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_5_12_SimpleClusterApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void keyDown( KeyEvent event );
	void update();
	void draw();
	
	msa::physics::World2D		mPhysics;
	Cluster						*mCluster;
	
	// Boolean that indicates whether we draw connections or not
	bool mShowPhysics = true;
	bool mShowParticles = true;
};

void NOC_5_12_SimpleClusterApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 640, 360 );
}

void NOC_5_12_SimpleClusterApp::setup()
{
	// Initialize the physics
	mPhysics.setGravity( Vec2f( 0.0, 0.1 ) );
	mPhysics.setWorldSize( Vec2f( 10.0, 10.0 ), Vec2f( getWindowWidth() - 20.0, getWindowHeight() - 20.0 ) );
	
	// Spawn a new random graph
	mCluster = new Cluster( &mPhysics, 8, 100, getWindowCenter() );
}

// Key press commands
void NOC_5_12_SimpleClusterApp::keyDown( KeyEvent event )
{
	if( event.getChar() == 'c' || event.getChar() == 'C' ){
		mShowPhysics = !mShowPhysics;
		if (!mShowPhysics) mShowParticles = true;
	}else if( event.getChar() == 'p' || event.getChar() == 'P' ){
		mShowParticles = !mShowParticles;
		if (!mShowParticles) mShowPhysics = true;

	} else if( event.getChar() == 'n' || event.getChar() == 'N' ){
		mPhysics.clear();
		mCluster = new Cluster( &mPhysics, int( randInt( 2, 20 ) ), randFloat( 10.0, getWindowWidth() / 2.0 ), getWindowCenter() );
	}
}


void NOC_5_12_SimpleClusterApp::update()
{
	// Update the physics world
	mPhysics.update();
}

void NOC_5_12_SimpleClusterApp::draw()
{
	gl::clear( Color::white() );
	
	// Display all points
	if( mShowParticles )
	{
		mCluster->display();
	}
	
	// If we want to see the physics
	if( mShowPhysics )
	{
		mCluster->showConnections();
	}
	
	// Instructions
	gl::color( Color::black() );
	TextBox tbox = TextBox().size( Vec2i( 200, TextBox::GROW ) ).text( "'p' to display or hide particles\n'c' to display or hide connections\n'n' for new graph" );
	tbox.setBackgroundColor( ColorA( 0, 0, 0, 0 ) );
	gl::enableAlphaBlending();
	glPushMatrix();
	gl::translate( Vec2f( 10.0, 20.0 ) );
	gl::draw(  gl::Texture( tbox.render() ) );
	glPopMatrix();

}

CINDER_APP_NATIVE( NOC_5_12_SimpleClusterApp, RendererGl )
