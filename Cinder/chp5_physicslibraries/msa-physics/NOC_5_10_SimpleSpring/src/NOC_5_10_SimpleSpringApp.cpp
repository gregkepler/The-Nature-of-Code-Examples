#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "MSAPhysics2D.h"
//#include "Particle.h"

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
	
	msa::physics::World2D		physics;
//	Particle					*p1, *p2;
	msa::physics::Particle2D	*p1, *p2;
	float						mRadius;
	bool						mMousePressed;
	Vec2f						mMousePos;
};

void NOC_5_10_SimpleSpringApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 640, 360 );
}

void NOC_5_10_SimpleSpringApp::setup()
{
	// Initialize the physics
	physics.setGravity( Vec2f(0, 1) );
	
	mRadius = 16;
	
	// Set the world's bounding box
	physics.setWorldSize( Vec2f::zero(), getWindowSize() );
	
	// Make two particles
	p1 = physics.makeParticle( Vec2f( getWindowWidth()/2, 20 ) );
	p2 = physics.makeParticle( Vec2f( getWindowWidth()/2 + 160, 20 ) );
	p1->setRadius( mRadius );
	p2->setRadius( mRadius );
	
	// Lock one in place
	p1->makeFixed();
	
	// Make a spring connecting both Particles
	physics.makeSpring( p1, p2, 0.1, 160.0 );
}

void NOC_5_10_SimpleSpringApp::mouseDown( MouseEvent event )
{
	mMousePressed = true;
	p2->makeFixed();
	mMousePos = event.getPos();
	p2->moveTo( mMousePos  );
}

void NOC_5_10_SimpleSpringApp::mouseUp( MouseEvent event )
{
	p2->makeFree();
	mMousePressed = false;
}

void NOC_5_10_SimpleSpringApp::mouseDrag( MouseEvent event )
{
	mMousePos = event.getPos();
}

void NOC_5_10_SimpleSpringApp::update()
{
	physics.update();
}

void NOC_5_10_SimpleSpringApp::draw()
{
	gl::clear( Color::white() );
	
	Vec2f pos1, pos2;
	pos1 = p1->getPosition();
	if( mMousePressed ){
		pos2 = mMousePos;
		p2->moveTo( pos2 );
	}else{
		pos2 =  p2->getPosition();
	}

	gl::lineWidth( 2.0 );
	gl::drawLine( pos1, pos2 );
	drawParticle( pos1 );
	drawParticle( pos2 );
}

void NOC_5_10_SimpleSpringApp::drawParticle( Vec2f pos )
{
	gl::color( Color8u::gray( 127 ) );
	gl::drawSolidEllipse( pos, mRadius, mRadius );
	gl::color( Color::black() );
	gl::drawStrokedEllipse( pos, mRadius, mRadius );
}

CINDER_APP_NATIVE( NOC_5_10_SimpleSpringApp, RendererGl )
