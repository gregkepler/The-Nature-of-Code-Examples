//
//  Face.cpp
//
//  Created by Greg Kepler
//
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

Face::Face( DNA* const dna, Vec2f loc )
{
	mGeneCounter = 0;
    mLocation = loc;
	mFitness = 1.0;
    mDna = dna;
	mRect = Rectf( loc.x - wh / 2.0, loc.y - wh / 2.0, loc.x + wh / 2.0, loc.y + wh );
}

Face::~Face()
{
	
}

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
//    noStroke();
	
    // Draw the head
	gl::color( c );
	gl::drawSolidEllipse( Vec2f::zero(), r/2, r/2 );
	
    // Draw the eyes
	
//    rectMode(CENTER);
//    rect(-eye_x, -eye_y, eye_size, eye_size);
//    rect( eye_x, -eye_y, eye_size, eye_size);
	gl::color( eyecolor );
	Vec2f leftEyePos  = Vec2f( -eye_x - eye_size / 2.0, -eye_y - eye_size/2.0 );
	Vec2f rightEyePos = Vec2f( eye_x - eye_size / 2.0, leftEyePos.y );
	gl::drawSolidRect( Rectf( leftEyePos.x, leftEyePos.y, leftEyePos.x + eye_size, leftEyePos.y + eye_size ) );
	gl::drawSolidRect( Rectf( rightEyePos.x, rightEyePos.y,  rightEyePos.x + eye_size, rightEyePos.y + eye_size ) );
	
    // Draw the mouth
//    fill(mouthColor);
//    rectMode(CENTER);
//    rect(mouth_x, mouth_y, mouthw, mouthh);
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
	
    // Display fitness value
//    textAlign(CENTER);
//    if (rolloverOn) fill(0);
//    else fill(0.25);
//    text(int(fitness), x, y+55);
	
	// reset the color
	gl::color( Color::white() ) ;
	
	Color textColor = (mRolloverOn) ? Color::black() : Color( 0.25, 0.25, 0.25 );
	textColor = Color::black();
	TextBox tbox = TextBox().alignment( TextBox::CENTER ).size( Vec2i( TextBox::GROW, TextBox::GROW ) ).text( to_string( mFitness ) );
	tbox.setColor( textColor );
	tbox.setBackgroundColor( ColorA( 0, 0, 0, 0.5 ) );
	gl::draw( tbox.render(), Vec2f( mLocation.x - tbox.getSize().x / 2.0, mLocation.y + 55.0) );

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