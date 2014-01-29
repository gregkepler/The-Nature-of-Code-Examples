//
//  Rocket.cpp
//  NOC_9_02_SmartRockets_superbasic
//
//  Created by Greg Kepler on 1/29/14.
//
//

#include "cinder/app/AppNative.h"
#include "Rocket.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Rocket::Rocket( Vec2f l, DNA dna_ ){
	mGeneCounter = 0;
	mHitTarget = false;
	
	mAcceleration = Vec2f::zero();
    mVelocity = Vec2f::zero();
    mLocation = l;
    r = 4;
    mDna = dna_;
}