#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Vehicle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_10_02_SeekingNeuralApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	void makeTargets();
	
	Vec2f			mDesired;
	Vehicle			*mVehicle;
	vector<Vec2f>	mTargets;
};

void NOC_10_02_SeekingNeuralApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_10_02_SeekingNeuralApp::setup()
{
	// The Vehicle's desired location
	mDesired = Vec2f( getWindowCenter() );
	
	
	// Create a list of targets
	makeTargets();
	
	// Create the Vehicle (it has to know about the number of targets
	// in order to configure its brain)
	mVehicle = new Vehicle( mTargets.size(), randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) );
}

// Make a random ArrayList of targets to steer towards
void NOC_10_02_SeekingNeuralApp::makeTargets() {
	/*targets = new ArrayList<PVector>();
	for (int i = 0; i < 8; i++) {
		targets.add(new PVector(random(width), random(height)));
	}*/
}

void NOC_10_02_SeekingNeuralApp::update()
{
}

void NOC_10_02_SeekingNeuralApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( NOC_10_02_SeekingNeuralApp, RendererGl )
