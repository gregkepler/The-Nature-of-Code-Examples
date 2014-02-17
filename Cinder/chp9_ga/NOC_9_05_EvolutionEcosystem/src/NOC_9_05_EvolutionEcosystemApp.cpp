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
	mWorld->run();
}

CINDER_APP_NATIVE( NOC_9_05_EvolutionEcosystemApp, RendererGl )
