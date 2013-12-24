#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "MSAPhysics2D.h"
#include "Particle.h"
#include "Attractor.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_5_13_AttractRepelApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
	void mouseUp( MouseEvent event );
	void mouseDrag( MouseEvent event );
	void update();
	void draw();
	
	msa::physics::World2D		mPhysics;
	vector<Particle*>			mParticles;
	Attractor					*mAttractor;
	bool						mMousePressed;
	Vec2f						mMousePos;
	
};

void NOC_5_13_AttractRepelApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 640, 360 );
}

void NOC_5_13_AttractRepelApp::setup()
{
	mPhysics.setGravity( Vec2f( 0.0, 0.0 ) );
	mPhysics.setDrag (0.01);
	
	mAttractor = new Attractor( &mPhysics, Vec2f( getWindowWidth() / 2, getWindowHeight() / 2 ) );
	
	for (int i = 0; i < 50; i++) {
		Particle *p = new Particle( Vec2f( randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) ) );
		mParticles.push_back( p );
		mAttractor->attractParticle( p );
	}
	
    for( int i = 0; i < mParticles.size() - 1; i++ )
	{
		Particle *pi = mParticles[i];
		for( int j = 0; j < mParticles.size(); j++ )
		{
			Particle *pj = mParticles[j];
			if(pi == pj) continue;
			mPhysics.makeAttraction( pi, pj, -1.0 );
			mPhysics.getAttraction( mPhysics.numberOfAttractions() - 1 )->setMaxDistance( 32.0 );
		}
    }
	
	
	mMousePressed = false;
}

void NOC_5_13_AttractRepelApp::mouseDown( MouseEvent event )
{
	mMousePressed = true;
	mMousePos = event.getPos();
}

void NOC_5_13_AttractRepelApp::mouseUp( MouseEvent event )
{
	mMousePressed = false;
}

void NOC_5_13_AttractRepelApp::mouseDrag( MouseEvent event )
{
	mMousePos = event.getPos();
}

void NOC_5_13_AttractRepelApp::update()
{
	mPhysics.update();
}

void NOC_5_13_AttractRepelApp::draw()
{
	gl::clear( Color::white() );
	
	mAttractor->display();
	for( vector<Particle*>::iterator p = mParticles.begin() + 1; p != mParticles.end(); ++p )
	{
		(*p)->display();
	}
		
	if (mMousePressed) {
		mAttractor->makeFixed();
		mAttractor->moveTo( mMousePos );
	} else {
		mAttractor->makeFree();
	}
}

CINDER_APP_NATIVE( NOC_5_13_AttractRepelApp, RendererGl )
