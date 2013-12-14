//
//  Example 5-7: Revolute Joint
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Example demonstrating revolute joint
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/Text.h"
#include "cinder/gl/Texture.h"
#include <Box2d/Box2D.h>
#include "Windmill.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_5_07_RevoluteJointApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	b2World*				mWorld;
	Windmill*				mWindmill;
	vector<Particle*>		mParticles;
};

void NOC_5_07_RevoluteJointApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 640, 360 );
}

void NOC_5_07_RevoluteJointApp::setup()
{
	// Initialize box2d physics and create the world
	b2Vec2 gravity( 0.0f, 10.0f );
    mWorld = new b2World( gravity );
	
	// Make the windmill at an x,y location
	mWindmill = new Windmill( mWorld, Vec2f( getWindowWidth() / 2.0, 175.0 ) );
}

// Click the mouse to turn on or off the motor
void NOC_5_07_RevoluteJointApp::mouseDown( MouseEvent event )
{
	mWindmill->toggleMotor();
}

void NOC_5_07_RevoluteJointApp::update()
{
	for( int i = 0; i < 2; ++i )
		mWorld->Step( 1 / 30.0f, 10, 10 );
}

void NOC_5_07_RevoluteJointApp::draw()
{
	gl::clear( Color::white() );
	glPushMatrix();
	
	
	if( randFloat( 1.0 ) < 0.1 ) {
		float sz = randFloat( 4.0, 8.0 );
		mParticles.push_back( new Particle( mWorld, Vec2f( randFloat( getWindowWidth() / 2 - 100, getWindowWidth() / 2 + 100 ) , -20.0 ), sz ) );
	}
	
	
	// Look at all particles
	// Draw all particles
	for( vector<Particle*>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ) {
		(*p)->display();
	}
	
	if(mParticles.size() > 0){
		for( vector<Particle*>::iterator p = mParticles.end()-1; p != mParticles.begin(); --p ) {
			if ((*p)->done()) {
				mParticles.erase( p );
			}
		}
	}

	// Draw the windmill
	mWindmill->display();
	
	glPopMatrix();
	
	
	// draw the text
	string status = "OFF";
	if( mWindmill->motorOn() ) status = "ON";
	
	TextBox tbox = TextBox().size( Vec2i( 200, TextBox::GROW ) ).text( "Click mouse to toggle motor.\nMotor: " + status );
	tbox.setBackgroundColor( ColorA( 0, 0, 0, 0 ) );
	Vec2i sz = tbox.measure();
	gl::enableAlphaBlending();
	glPushMatrix();
	gl::translate( Vec2f( 10.0, getWindowHeight() - sz.y -10.0 ) );
	gl::draw(  gl::Texture( tbox.render() ) );
	glPopMatrix();
}

CINDER_APP_NATIVE( NOC_5_07_RevoluteJointApp, RendererGl )
