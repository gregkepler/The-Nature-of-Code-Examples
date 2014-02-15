//
//  Face.cpp
//
//  Created by Greg Kepler
//
//	The class for our "face", contains DNA sequence, fitness value, position on screen
//	Fitness Function f(t) = t (where t is "time" mouse rolls over face)
//

#include "cinder/app/AppNative.h"
#include "cinder/CinderMath.h"
#include "cinder/Text.h"
#include "cinder/gl/Texture.h"
#include "Face.h"


using namespace ci;
using namespace ci::app;
using namespace std;

const int wh = 70;				// Size of square enclosing face

// Create a new face
Face::Face( DNA* dna, Vec2f loc )
{
    mLocation = loc;
	mFitness = 1.0;
    mDna = dna;
	mRect = Rectf( loc.x - wh / 2.0, loc.y - wh / 2.0, loc.x + wh / 2.0, loc.y + wh / 2.0 );
}

Face::~Face()
{
	delete mDna;
}

// Display the face
void Face::display()
{
	// We are using the face's DNA to pick properties for this face
    // such as: head size, color, eye position, etc.
    // Now, since every gene is a floating point between 0 and 1, we map the values
    float r          = lmap( mDna->mGenes[0], 0.0f, 1.0f, 0.0f, 70.0f );
    Color c          = Color( mDna->mGenes[1], mDna->mGenes[2], mDna->mGenes[3] );
    float eye_y      = lmap( mDna->mGenes[4], 0.0f, 1.0f, 0.0f, 5.0f );
    float eye_x      = lmap( mDna->mGenes[5], 0.0f, 1.0f, 0.0f, 10.0f );
    float eye_size   = lmap( mDna->mGenes[5], 0.0f, 1.0f, 0.0f, 10.0f );
    Color eyecolor   = Color( mDna->mGenes[4], mDna->mGenes[5], mDna->mGenes[6] );
    Color mouthColor = Color( mDna->mGenes[7], mDna->mGenes[8], mDna->mGenes[9] );
    float mouth_y    = lmap( mDna->mGenes[5], 0.0f, 1.0f, 0.0f, 25.0f );
    float mouth_x    = lmap( mDna->mGenes[5], 0.0f, 1.0f, -25.0f, 25.0f );
    float mouthw     = lmap( mDna->mGenes[5], 0.0f, 1.0f, 0.0f, 50.0f );
    float mouthh     = lmap( mDna->mGenes[5], 0.0f, 1.0f, 0.0f, 10.0f );
	
    // Once we calculate all the above properties, we use those variables to draw rects, ellipses, etc.
	gl::pushMatrices();
	gl::translate( mLocation );
	
    // Draw the head
	gl::color( c );
	gl::drawSolidEllipse( Vec2f::zero(), r/2, r/2 );
	
    // Draw the eyes
	gl::color( eyecolor );
	Vec2f leftEyePos  = Vec2f( -eye_x - eye_size / 2.0, -eye_y - eye_size/2.0 );
	Vec2f rightEyePos = Vec2f( eye_x - eye_size / 2.0, leftEyePos.y );
	gl::drawSolidRect( Rectf( leftEyePos.x, leftEyePos.y, leftEyePos.x + eye_size, leftEyePos.y + eye_size ) );
	gl::drawSolidRect( Rectf( rightEyePos.x, rightEyePos.y,  rightEyePos.x + eye_size, rightEyePos.y + eye_size ) );
	
    // Draw the mouth
	gl::color( mouthColor );
	Vec2f mouthPos = Vec2f( mouth_x - mouthw / 2, mouth_y - mouthh / 2 );
	gl::drawSolidRect( Rectf( mouthPos.x, mouthPos.y, mouthPos.x + mouthw, mouthPos.y + mouthh ) );
	
    // Draw the bounding box
	gl::color( Color( 0.25, 0.25, 0.25 ) );
	if( mRolloverOn ){
		gl::color( ColorA( 0, 0, 0, 0.25 ) );
		gl::drawSolidRect( Rectf( -wh/2, -wh/2, -wh/2 + wh, -wh/2 + wh ) );
	}
	gl::drawStrokedRect( Rectf( -wh/2, -wh/2, -wh/2 + wh, -wh/2 + wh ) );
	gl::popMatrices();
		
	// reset the color
	gl::color( Color::white() ) ;
	
	Color textColor = (mRolloverOn) ? Color::black() : Color( 0.25, 0.25, 0.25 );
	TextBox tbox = TextBox().alignment( TextBox::CENTER ).size( Vec2i( wh, TextBox::GROW ) ).text( to_string( int( mFitness ) ) );
	tbox.setColor( textColor );
	tbox.setBackgroundColor( ColorA( 0, 0, 0, 0.0 ) );
	gl::pushMatrices();
	gl::translate(mLocation.x - wh/2, mLocation.y + 45.0 );
	gl::draw( tbox.render() );
	gl::popMatrices();
}

DNA* Face::getDNA()
{
	return mDna;
}

float Face::getFitness()
{
	return mFitness;
}

// Increment fitness if mouse is rolling over face
void Face::rollover( Vec2f loc )
{
	if( mRect.contains( loc ) ) {
		mRolloverOn = true;
		mFitness += 0.25;
    } else {
		mRolloverOn = false;
    }
}