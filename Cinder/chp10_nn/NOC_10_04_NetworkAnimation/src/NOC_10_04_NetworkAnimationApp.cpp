#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Network.h"
#include "Neuron.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_10_04_NetworkAnimationApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	Network *mNetwork;
};

void NOC_10_04_NetworkAnimationApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_10_04_NetworkAnimationApp::setup()
{
	// Create the Network object
	mNetwork = new Network( getWindowSize() / 2 );
	
	// Create a bunch of Neurons
	Neuron *a = new Neuron( Vec2i( -275, 0 ) );
	Neuron *b = new Neuron( Vec2i( -150, 0 ) );
	Neuron *c = new Neuron( Vec2i( 0, 75 ) );
	Neuron *d = new Neuron( Vec2i( 0, -75 ) );
	Neuron *e = new Neuron( Vec2i( 150, 0 ) );
	Neuron *f = new Neuron( Vec2i( 275, 0 ) );
	
	// Connect them
	mNetwork->connect( a, b, 1.0 );
	mNetwork->connect( b, c, randFloat() );
	mNetwork->connect( b, d, randFloat() );
	mNetwork->connect( c, e, randFloat() );
	mNetwork->connect( d, e, randFloat() );
	mNetwork->connect( e, f, 1.0 );
	
	// Add them to the Network
	mNetwork->addNeuron( a );
	mNetwork->addNeuron( b );
	mNetwork->addNeuron( c );
	mNetwork->addNeuron( d );
	mNetwork->addNeuron( e );
	mNetwork->addNeuron( f );
}

void NOC_10_04_NetworkAnimationApp::mouseDown( MouseEvent event )
{
}

void NOC_10_04_NetworkAnimationApp::update()
{
	mNetwork->update();
}

void NOC_10_04_NetworkAnimationApp::draw()
{
	gl::clear( Color::white() );
	
	// Draw the Network
	mNetwork->display();
	
	// Every 30 frames feed in an input
	if( getElapsedFrames() % 30 == 0 ) {
		mNetwork->feedforward( randFloat() );
	}
}

CINDER_APP_NATIVE( NOC_10_04_NetworkAnimationApp, RendererGl )
