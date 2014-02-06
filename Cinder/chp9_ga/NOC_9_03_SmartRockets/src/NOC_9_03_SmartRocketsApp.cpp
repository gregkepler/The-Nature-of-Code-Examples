//
//  Example 9-3: Smart Rockets
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Smart Rockets w/ Genetic Algorithms
//
//	Each Rocket's DNA is an array of Vec2fs
//	Each Vec2f acts as a force for each frame of animation
//	Imagine a booster on the end of the rocket that can point in any direction
//	and fire at any strength every frame
//
//	The Rocket's fitness is a function of how close it gets to the target as well as how fast it gets there
//
//	This example is inspired by Jer Thorp's Smart Rockets
//	http://www.blprnt.com/smartrockets/
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Text.h"
#include "cinder/gl/Texture.h"
#include "Population.h"
#include "Obstacle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_9_03_SmartRocketsApp : public AppNative {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
	void update();
	void draw();
	void drawText( string str, Vec2i pos );
	
	int					mLifetime;			// How long should each generation live
	Population			*mPopulation;		// Population
	int					mLifeCycle;			// Timer for cycle of generation
	int					mRecordtime;		// Fastest time to target
	Obstacle			*mTarget;				// Target location
	vector<Obstacle*>	mObstacles;			// a vector to keep track of all the obstacles!
};

void NOC_9_03_SmartRocketsApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_9_03_SmartRocketsApp::setup()
{
	// The number of cycles we will allow a generation to live
	mLifetime = 300;
	
	// Initialize variables
	mLifeCycle = 0;
	mRecordtime = mLifetime;
	
	mTarget = new Obstacle( Vec2f( ( getWindowWidth() / 2.0 ) - 12.0, 24.0 ), 24.0, 24.0 );
	
	// Create a population with a mutation rate, and population max
	float mutationRate = 0.01;
	mPopulation = new Population( mutationRate, 50, mTarget, mLifetime );
	
	// Create the obstacle course
	mObstacles.push_back( new Obstacle( Vec2f( ( getWindowWidth() / 2.0 ) - 100.0, getWindowHeight() / 2 ), 200.0, 10.0) );
}

void NOC_9_03_SmartRocketsApp::update()
{
}

void NOC_9_03_SmartRocketsApp::draw()
{
	// clear out the window with black
	gl::clear( Color::white() );
	gl::enableAlphaBlending();
	
	// Draw the start and target locations
	mTarget->display();
	
	// If the generation hasn't ended yet
	if( mLifeCycle < mLifetime )
	{
		mPopulation->live( &mObstacles );
		if( ( mPopulation->targetReached() ) && ( mLifeCycle < mRecordtime ) )
		{
			mRecordtime = mLifeCycle;
		}
		mLifeCycle++;
		// Otherwise a new generation
	}
	else
	{
		mLifeCycle = 0;
		mPopulation->fitness();
		mPopulation->selection();
		mPopulation->reproduction();
	}
	
	// Draw the obstacles
	for( Obstacle *obs : mObstacles )
	{
		obs->display();
	}
	
	// Display some info
	gl::color( Color::black() );
	drawText("Generation #: " + to_string( mPopulation->getGenerations() ), Vec2i( 10, 10 ) );
	drawText("Cycles left: " + to_string( mLifetime - mLifeCycle ), Vec2i( 10, 28 ) );
	drawText("Record cycles: " + to_string( mRecordtime ), Vec2i( 10, 54 ) );
}

void NOC_9_03_SmartRocketsApp::drawText( string str, Vec2i pos )
{
	TextBox tbox = TextBox().alignment( TextBox::LEFT ).size( Vec2i( getWindowWidth(), TextBox::GROW ) ).text( str );
	tbox.setColor( Color::black() );
	tbox.setBackgroundColor( ColorA( 0, 0, 0, 0 ) );
	gl::draw( tbox.render(), pos );
}

// Move the target if the mouse is pressed
// System will adapt to new target
void NOC_9_03_SmartRocketsApp::mouseDown( MouseEvent event )
{
	mTarget->mLocation.x = event.getX();
	mTarget->mLocation.y = event.getY();
	mRecordtime = mLifetime;
}

CINDER_APP_NATIVE( NOC_9_03_SmartRocketsApp, RendererGl )
