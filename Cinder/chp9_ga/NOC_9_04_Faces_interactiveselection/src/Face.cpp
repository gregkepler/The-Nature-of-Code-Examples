//
//  Face.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "Face.h"
#include "cinder/CinderMath.h"

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
	gl::drawSolidEllipse( Vec2f::zero(), r, r );
	
    // Draw the eyes
	gl::color( eyecolor );
//    rectMode(CENTER);
//    rect(-eye_x, -eye_y, eye_size, eye_size);
//    rect( eye_x, -eye_y, eye_size, eye_size);
	gl::drawSolidRect( Rectf( -eye_x, -eye_y, -eye_x + eye_size, -eye_y + eye_size ) );
	
    // Draw the mouth
    fill(mouthColor);
    rectMode(CENTER);
    rect(mouth_x, mouth_y, mouthw, mouthh);
	
    // Draw the bounding box
    stroke(0.25);
    if (rolloverOn) fill(0, 0.25);
    else noFill();
    rectMode(CENTER);
    rect(0, 0, wh, wh);
	gl::popMatrices();
	
    // Display fitness value
    textAlign(CENTER);
    if (rolloverOn) fill(0);
    else fill(0.25);
    text(int(fitness), x, y+55);}

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