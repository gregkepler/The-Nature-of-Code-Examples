#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Network.h"
#include "Neuron.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_10_03_NetworkVizApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Network *mNetwork;
	bool	mRunning;
};

void NOC_10_03_NetworkVizApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_10_03_NetworkVizApp::setup()
{
	// Create the Network object
	mNetwork = new Network( getWindowSize() / 2 );
	
	// Create a bunch of Neurons
	Neuron *a = new Neuron( Vec2i( -200, 0 ) );
	Neuron *b = new Neuron( Vec2i( 0, 75 ) );
	Neuron *c = new Neuron( Vec2i( 0, -75 ) );
	Neuron *d = new Neuron( Vec2i( 200, 0 ) );
	
	// Connect them
	mNetwork->connect( a, b );
	mNetwork->connect( a, c );
	mNetwork->connect( b, d );
	mNetwork->connect( c, d );
	
	// Add them to the Network
	mNetwork->addNeuron( a );
	mNetwork->addNeuron( b );
	mNetwork->addNeuron( c );
	mNetwork->addNeuron( d );
	
	mRunning = false;
}


void NOC_10_03_NetworkVizApp::update()
{
}

void NOC_10_03_NetworkVizApp::draw()
{
	if( mRunning ) return;
	gl::clear( Color::white() );
	mNetwork->display();
	mRunning = true;
}

CINDER_APP_NATIVE( NOC_10_03_NetworkVizApp, RendererGl )
