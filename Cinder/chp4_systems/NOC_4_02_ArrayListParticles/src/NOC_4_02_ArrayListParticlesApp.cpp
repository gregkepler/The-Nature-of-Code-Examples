//
//  Example 4-2: ArrayList Particles
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Since ArrayList doesn't exist in C++, std::vector is used instead
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_4_02_ArrayListParticlesApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
	void update();
	void draw();
	
	vector<Particle> mParticles;
};

void NOC_4_02_ArrayListParticlesApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}


void NOC_4_02_ArrayListParticlesApp::setup()
{
	mParticles = vector<Particle>();
}

void NOC_4_02_ArrayListParticlesApp::mouseDown( MouseEvent event )
{
}

void NOC_4_02_ArrayListParticlesApp::update()
{
}

void NOC_4_02_ArrayListParticlesApp::draw()
{
	// clear out the window with black
	gl::clear( Color::white() );
	mParticles.push_back( Particle( Vec2f( getWindowWidth() / 2, 50 ) ) );
	
	// Looping through backwards to delete
	/*for( int i = mParticles.size()-1; i >= 0; i-- ) {
		Particle p = mParticles.at( i );
		p.run();
		if ( p.isDead() ) {
			// must provide iterator in the erase function
			mParticles.erase( mParticles.begin() + i );
		}
	}*/
	
	for( vector<Particle>::iterator it = mParticles.end() - 1; it != mParticles.begin(); --it ) {
		it->run();
		if ( it->isDead() ) {
			// must provide iterator in the erase function
			mParticles.erase( it );
		}
	}
}

CINDER_APP_NATIVE( NOC_4_02_ArrayListParticlesApp, RendererGl )
