#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Trainer.h"
#include "Perceptron.h"

using namespace ci;
using namespace ci::app;
using namespace std;

// Coordinate space
static const float xmin = -400.0;
static const float ymin = -100.0;
static const float xmax =  400.0;
static const float ymax =  100.0;

class NOC_10_01_SimplePerceptronApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	float f( float x );
	
	vector<Trainer*>	mTraining;
	Perceptron			*mPtron;
	
	int					mCount;		// We will train the perceptron with one "Point" object at a time
};

void NOC_10_01_SimplePerceptronApp::setup()
{
	// The perceptron has 3 inputs -- x, y, and bias
	// Second value is "Learning Constant"
	mPtron = new Perceptron(3, 0.00001);  // Learning Constant is low just b/c it's fun to watch, this is not necessarily optimal
	
	mTraining.resize( 2000 );
	// Create a random set of training points and calculate the "known" answer
	for (int i = 0; i < mTraining.size(); i++) {
		float x = randFloat( xmin, xmax );
		float y = randFloat( ymin, ymax );
		int answer = 1;
		if (y < f(x)) answer = -1;
		mTraining.push_back( new Trainer( x, y, answer ) );
	}
	
	mCount = 0;
}

// The function to describe a line
float NOC_10_01_SimplePerceptronApp::f( float x )
{
	return 0.4 * x + 1;
}

void NOC_10_01_SimplePerceptronApp::mouseDown( MouseEvent event )
{
}

void NOC_10_01_SimplePerceptronApp::update()
{
}

void NOC_10_01_SimplePerceptronApp::draw()
{
	gl::clear( Color::white() );
	
	gl::pushMatrices();
	gl::translate( getWindowCenter() / 2.0 );
	
	// Draw the line
	gl::lineWidth( 4.0 );
	gl::color( Color8u::gray( 127 ) );
	float x1 = xmin;
	float y1 = f( x1 );
	float x2 = xmax;
	float y2 = f( x2 );
	gl::drawLine( Vec2f( x1, y1 ), Vec2f( x2, y2 ) );
	
	// Draw the line based on the current weights
	// Formula is weights[0]*x + weights[1]*y + weights[2] = 0
	gl::color( Color::black() );
	gl::lineWidth( 1.0 );

	vector<float> weights = mPtron->getWeights();
	x1 = xmin;
	y1 = ( -weights[2] - weights[0] * x1 ) / weights[1];
	x2 = xmax;
	y2 = ( -weights[2] - weights[0] * x2 ) / weights[1];
	gl::drawLine( Vec2f( x1, y1 ), Vec2f( x2, y2 ) );
	
	

	// Train the Perceptron with one "training" point at a time
	mPtron->train( mTraining[mCount]->mInputs, mTraining[mCount]->mAnswer );
	mCount = ( mCount + 1) % mTraining.size();
	
	// Draw all the points based on what the Perceptron would "guess"
	// Does not use the "known" correct answer
	for( int i = 0; i < mCount; i++ )
	{
		int guess = mPtron->feedforward( mTraining[i]->mInputs );
		ColorA fillColor = (guess > 0) ? ColorA( 1, 1, 1, 0 ) : ColorA::black();
		gl::color( fillColor );
		
		gl::drawSolidEllipse( Vec2f( mTraining[i]->mInputs[0], mTraining[i]->mInputs[1] ), 4.0, 4.0 );
		
		gl::color( Color::black() );
		gl::lineWidth( 1.0 );
		gl::drawStrokedEllipse( Vec2f( mTraining[i]->mInputs[0], mTraining[i]->mInputs[1] ), 4.0, 4.0 );
	}
	
	gl::popMatrices();
	
}

CINDER_APP_NATIVE( NOC_10_01_SimplePerceptronApp, RendererGl )
