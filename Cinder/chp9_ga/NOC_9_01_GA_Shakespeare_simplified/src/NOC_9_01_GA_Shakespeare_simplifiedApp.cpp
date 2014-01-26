//
//  Example 9-1: GA Shakespeare Simplified
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
//    # Create an empty population (an array or vector)
//    # Fill it with DNA encoded objects (pick random values to start)
//
//	draw()
//  # Step 1: Selection
//    # Create an empty mating pool (an empty vector)
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
#include "cinder/gl/Texture.h"
#include "cinder/Text.h"
#include "cinder/Rand.h"
#include "DNA.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_9_01_GA_Shakespeare_simplifiedApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Font	mFont;
	float		mMutationRate = 0.01;			// Mutation rate
	int			mTotalPopulation = 150;			// Total Population
	vector<DNA>	mPopulation;					// Array to hold the current population
	vector<DNA> mMatingPool;					// ArrayList which we will use for our "mating pool"
	string		mTarget;						// Target phrase
};

void NOC_9_01_GA_Shakespeare_simplifiedApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 850, 200 );
}

void NOC_9_01_GA_Shakespeare_simplifiedApp::setup()
{
	mTarget = "To be or not to be.";
	
	mPopulation.resize( mTotalPopulation );
	
	for( int i = 0; i < mPopulation.size(); i++ )
	{
		mPopulation[i] = DNA( mTarget.length() );
	}
	mFont = Font( "Courier", 12 );
}

void NOC_9_01_GA_Shakespeare_simplifiedApp::update()
{
}

void NOC_9_01_GA_Shakespeare_simplifiedApp::draw()
{
	for( int i = 0; i < mPopulation.size(); i++ )
	{
		mPopulation[i].calcFitness( mTarget );
	}
	
	mMatingPool.clear();									// ArrayList which we will use for our "mating pool"
	
	for( int i = 0; i < mPopulation.size(); i++ )
	{
		int nnnn = int( mPopulation[i].mFitness * 100);		// Arbitrary multiplier, we can also use monte carlo method
		for( int j = 0; j <nnnn; j++ )						// and pick two random numbers
		{
			mMatingPool.push_back( mPopulation[i] );
		}
	}
	
	for (int i = 0; i < mPopulation.size(); i++)
	{
		int a = randInt( mMatingPool.size() );
		int b = randInt( mMatingPool.size() );
		DNA partnerA = mMatingPool[a];
		DNA partnerB = mMatingPool[b];
		DNA child = partnerA.crossover( partnerB );
		child.mutate( mMutationRate );
		mPopulation[i] = child;
	}
	
	gl::clear( Color::white() );
	gl::enableAlphaBlending();
	gl::color( Color::black() );
	string everything = "";
	for( int i = 0; i < mPopulation.size(); i++ )
	{
		everything += mPopulation[i].getPhrase() + "     ";
	}
	
	TextBox tbox = TextBox().alignment( TextBox::LEFT ).font( mFont ).size( Vec2i( getWindowWidth() - 20, TextBox::GROW ) ).text( everything );
	tbox.setColor( Color::black() );
	tbox.setBackgroundColor( ColorA( 0, 0, 0, 0 ) );
	gl::draw( tbox.render(), Vec2f( 10, 10 ) );

}

CINDER_APP_NATIVE( NOC_9_01_GA_Shakespeare_simplifiedApp, RendererGl )
