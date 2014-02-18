//
//  Food.cpp
//  NOC_9_05_EvolutionEcosystem
//
//  Created by Greg Kepler on 2/18/14.
//
//

#include "cinder/Rand.h"
#include "Food.h"


using namespace ci;
using namespace ci::app;
using namespace std;

Food::Food( int num )
{
    // Start with some food
    for( int i = 0; i < num; i++ )
	{
		mFood.push_back( randVec2f() * Vec2f( getWindowSize() ) );
    }
}

// Add some food at a location
void Food::add( Vec2f l )
{
	mFood.push_back( l );
}

// Display the food
void Food::run()
{
    for( Vec2f f : mFood ) {
		Rectf rect = Rectf( f.x - 4.0, f.y-4.0, f.x + 4.0, f.y + 4.0 );
		gl::color( Color8u::gray( 175 ) );
		gl::drawSolidRect( rect );
		gl::color( Color::black() );
		gl::drawStrokedRect( rect );    }
    
    // There's a small chance food will appear randomly
    if( randFloat() < 0.001 )
	{
		mFood.push_back( randVec2f() * Vec2f( getWindowSize() ) );
    }
}

// Return the list of food
vector<Vec2f>* Food::getFood() {
    return &mFood;
}