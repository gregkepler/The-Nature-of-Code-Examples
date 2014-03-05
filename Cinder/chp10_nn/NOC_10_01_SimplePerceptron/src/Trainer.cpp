//
//  Trainer.cpp
//  NOC_10_01_SimplePerceptron
//
//  Created by Greg Kepler on 2/25/14.
//
//

#include "cinder/app/AppNative.h"
#include "Trainer.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Trainer::Trainer( float x, float y, int a )
{
	mInputs.resize( 3 );
    mInputs[0] = x;
    mInputs[1] = y;
    mInputs[2] = 1;
    mAnswer = a;
}
