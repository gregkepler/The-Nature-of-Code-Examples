//
//  Example 9-1: GA Shakespeare
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//	Genetic Algorithm, Evolving Shakespeare
//
//	Demonstration of using a genetic algorithm to perform a search
//
//	setup()
//  # Step 1: The Population
//    # Create an empty population (an array or ArrayList)
//    # Fill it with DNA encoded objects (pick random values to start)
//
//	draw()
//  # Step 1: Selection
//    # Create an empty mating pool (an empty ArrayList)
//    # For every member of the population, evaluate its fitness based on some criteria / function,
//      and add it to the mating pool in a manner consistant with its fitness, i.e. the more fit it
//      is the more times it appears in the mating pool, in order to be more likely picked for reproduction.
//
//  # Step 2: Reproduction Create a new empty population
//    # Fill the new population by executing the following steps:
//       1. Pick two "parent" objects from the mating pool.
//       2. Crossover -- create a "child" object by mating these two parents.
//       3. Mutation -- mutate the child's DNA based on a given probability.
//       4. Add the child object to the new population.
//    # Replace the old population with the new population
//
//   # Rinse and repeat

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Text.h"
#include "cinder/gl/Texture.h"
#include "Population.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_9_01_GA_ShakespeareApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void displayInfo();
	void drawText( string str, int fontSize, Vec2i pos );
	
	Font	mFont;
	string	mTarget;
	int		mPopmax;
	float	mMutationRate;
	bool	mFinished;
	
	Population *mPopulation;
};

void NOC_9_01_GA_ShakespeareApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_9_01_GA_ShakespeareApp::setup()
{
	mFinished = false;
	mFont = Font( "Courier", 32 );
	mTarget = "To be or not to be.";
	mPopmax = 150;
	mMutationRate = 0.01;
	
	// Create a populationation with a target phrase, mutation rate, and populationation max
	mPopulation = new Population( mTarget, mMutationRate, mPopmax);
}

void NOC_9_01_GA_ShakespeareApp::mouseDown( MouseEvent event )
{
}

void NOC_9_01_GA_ShakespeareApp::update()
{
}

void NOC_9_01_GA_ShakespeareApp::draw()
{
	// If we found the target phrase, don't redraw
	if( mFinished ) return;
	
	// Generate mating pool
	mPopulation->naturalSelection();
	//Create next generation
	mPopulation->generate();
	// Calculate fitness
	mPopulation->calcFitness();
	displayInfo();
	
	
	if( mPopulation->finished() ) {
		console() << getElapsedSeconds() << endl;
		mFinished = true;
	}
}

void NOC_9_01_GA_ShakespeareApp::displayInfo()
{
	
	
	gl::clear( Color::white() );
	gl::enableAlphaBlending();
	
	// Display current status of populationation
	string answer = mPopulation->getBest();
	
	/*textFont(f);
	textAlign(LEFT);
	fill(0);
	
	
	textSize(24);
	text("Best phrase:",20,30);
	textSize(40);
	text(answer, 20, 100);
	
	textSize(18);
	text("total generations:     " + population.getGenerations(), 20, 160);
	text("average fitness:       " + nf(population.getAverageFitness(), 0, 2), 20, 180);
	text("total population: " + popmax, 20, 200);
	text("mutation rate:         " + int(mutationRate * 100) + "%", 20, 220);
	
	textSize(10);
	text("All phrases:\n" + population.allPhrases(), 500, 10);*/

	drawText( "Best Phrase:", 24, Vec2i(20, 30) );
	drawText( answer, 40, Vec2i(20, 100) );
	drawText( "total generations:     " + to_string( mPopulation->getGenerations() ), 18, Vec2i(20, 160) );
	drawText( "average fitness:     " + to_string( mPopulation->getAverageFitness() ), 18, Vec2i(20, 180) );
	drawText( "total population:     " + to_string( mPopmax ), 18, Vec2i(20, 200) );
	drawText( "mutation rate:     " + to_string( int( mMutationRate * 100 ) ) + "%", 18, Vec2i(20, 220) );
	drawText( "All phrases:\n" + mPopulation->allPhrases(), 10, Vec2i(500, 10) );
	
	/*Font font = Font( mFont.getName(), 24 );

	TextBox tbox = TextBox().alignment( TextBox::LEFT ).font( font ).size( Vec2i( getWindowWidth(), TextBox::GROW ) ).text( "Best Phrase:" );
	tbox.setColor( Color::black() );
	tbox.setBackgroundColor( ColorA( 0, 0, 0, 0 ) );
	gl::draw( tbox.render(), Vec2f( 20, 30 ) );
	
	font = Font( mFont.getName(), 40 );
	tbox = TextBox().alignment( TextBox::LEFT ).font( font ).size( Vec2i( getWindowWidth(), TextBox::GROW ) ).text( answer );
	tbox.setColor( Color::black() );
	tbox.setBackgroundColor( ColorA( 0, 0, 0, 0 ) );
	gl::draw( tbox.render(), Vec2f( 20, 100 ) );

	
	font = Font( mFont.getName(), 18 );
	tbox = TextBox().alignment( TextBox::LEFT ).font( font ).size( Vec2i( getWindowWidth(), TextBox::GROW ) ).text( answer );
	tbox.setColor( Color::black() );
	tbox.setBackgroundColor( ColorA( 0, 0, 0, 0 ) );
	gl::draw( tbox.render(), Vec2f( 20, 100 ) );*/

	
}

void NOC_9_01_GA_ShakespeareApp::drawText( string str, int fontSize, Vec2i pos )
{
	Font font = Font( mFont.getName(), fontSize );
	TextBox tbox = TextBox().alignment( TextBox::LEFT ).font( font ).size( Vec2i( getWindowWidth(), TextBox::GROW ) ).text( str );
	tbox.setColor( Color::black() );
	tbox.setBackgroundColor( ColorA( 0, 0, 0, 0 ) );
	gl::draw( tbox.render(), pos );
}

CINDER_APP_NATIVE( NOC_9_01_GA_ShakespeareApp, RendererGl )
