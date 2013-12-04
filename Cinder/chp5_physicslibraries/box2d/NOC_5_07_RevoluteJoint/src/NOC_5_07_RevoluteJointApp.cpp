//
//  Example 5-7: Revolute Joint
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Example demonstrating revolute joints
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <Box2d/Box2D.h>
#include "Windmill.h"

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
	
};

void NOC_5_07_RevoluteJointApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 640, 360 );
}

void NOC_5_07_RevoluteJointApp::setup()
{
	b2Vec2 gravity( 0.0f, 10.0f );
    mWorld = new b2World( gravity );
	
	// Make the windmill at an x,y location
	mWindmill = new Windmill( mWorld, Vec2f( getWindowWidth() / 2.0, 175.0 ) );
}

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
	
	if( randFloat( 1.0 ) < 0.1 ) {
		float sz = randFloat( 4.0, 8.0 );
//		particles.add(new Particle(random(width/2-100,width/2+100),-20,sz));
	}
	
	
	// Look at all particles
	/*for (int i = particles.size()-1; i >= 0; i--) {
		Particle p = particles.get(i);
		p.display();
		// Particles that leave the screen, we delete them
		// (note they have to be deleted from both the box2d world and our list
		if (p.done()) {
			particles.remove(i);
		}
	}*/
	
	// Draw the windmill
	mWindmill->display();
	/*
	String status = "OFF";
	if (windmill.motorOn()) status = "ON";
	
	fill(0);
	text("Click mouse to toggle motor.\nMotor: " + status,10,height-30);
	*/

}

CINDER_APP_NATIVE( NOC_5_07_RevoluteJointApp, RendererGl )
