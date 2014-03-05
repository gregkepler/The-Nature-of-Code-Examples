//
//  Example 9-5: Evolution Ecosystem
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//	A World of creatures that eat food
//	The more they eat, the longer they survive
//	The longer they survive, the more likely they are to reproduce
//	The bigger they are, the easier it is to land on food
//	The bigger they are, the slower they are to find food
//	When the creatures die, food is left behind
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "World.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_9_05_EvolutionEcosystemApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
	void mouseDrag( MouseEvent event );
	void update();
	void draw();
	
	World	*mWorld;
};

void NOC_9_05_EvolutionEcosystemApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_9_05_EvolutionEcosystemApp::setup()
{
	// World starts with 20 creatures
	// and 20 pieces of food
	mWorld = new World( 20 );
}

void NOC_9_05_EvolutionEcosystemApp::mouseDown( MouseEvent event )
{
	mWorld->born( event.getPos() );
}

void NOC_9_05_EvolutionEcosystemApp::mouseDrag( MouseEvent event )
{
	mWorld->born( event.getPos() );
}

void NOC_9_05_EvolutionEcosystemApp::update()
{
}

void NOC_9_05_EvolutionEcosystemApp::draw()
{
	gl::clear( Color::white() );
	gl::enableAlphaBlending();
	mWorld->run();
}

CINDER_APP_NATIVE( NOC_9_05_EvolutionEcosystemApp, RendererGl )
