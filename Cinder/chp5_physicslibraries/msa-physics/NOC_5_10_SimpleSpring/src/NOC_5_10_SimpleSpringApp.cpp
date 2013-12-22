//
//  Example 5-10: Simple Spring
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Simple MSA Physics Spring
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "MSAPhysics2D.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_5_10_SimpleSpringApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
	void mouseUp( MouseEvent event );
	void mouseDrag( MouseEvent event );
	void update();
	void draw();
	void drawParticle( Vec2f pos );
	
	msa::physics::World2D		mPhysics;
	Particle					*p1, *p2;
	bool						mMousePressed;
};

void NOC_5_10_SimpleSpringApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 640, 360 );
}

void NOC_5_10_SimpleSpringApp::setup()
{
	// Initialize the mPhysics
	mPhysics.setGravity( Vec2f(0, 1) );
	
	// Set the world's bounding box
	mPhysics.setWorldSize( Vec2f::zero(), getWindowSize() );
	
	// Make two particles and lock one in place
	p1 = new Particle( Vec2f( getWindowWidth() / 2, 20 ));
	p2 = new Particle( Vec2f( getWindowWidth() / 2 + 160, 20 ));
	
	// Lock one in place
	p1->makeFixed();
	
	// Anything we make, we have to add into the physics world
	mPhysics.addParticle( p1 );
	mPhysics.addParticle( p2 );
	
	// Make a spring connecting both Particles
	mPhysics.makeSpring( p1, p2, 0.1, 160.0 );
}

void NOC_5_10_SimpleSpringApp::mouseDown( MouseEvent event )
{
	mMousePressed = true;
	p2->makeFixed();
	p2->moveTo( event.getPos() );
}

void NOC_5_10_SimpleSpringApp::mouseUp( MouseEvent event )
{
	p2->makeFree();
	mMousePressed = false;
	
}

void NOC_5_10_SimpleSpringApp::mouseDrag( MouseEvent event )
{
	p2->moveTo( event.getPos() );
}

void NOC_5_10_SimpleSpringApp::update()
{
	mPhysics.update();
}

void NOC_5_10_SimpleSpringApp::draw()
{
	gl::clear( Color::white() );
	gl::lineWidth( 2.0 );
	gl::drawLine( p1->getPosition(), p2->getPosition() );
	p1->display();
	p2->display();
}


CINDER_APP_NATIVE( NOC_5_10_SimpleSpringApp, RendererGl )
