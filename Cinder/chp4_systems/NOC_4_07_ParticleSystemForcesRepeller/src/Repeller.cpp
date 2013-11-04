//
//  Repeller.cpp
//  NOC_4_07_ParticleSystemForcesRepeller
//
//  Created by Greg Kepler on 11/4/13.
//
//

#include "Cinder/app/AppBasic.h"
#include "Repeller.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Repeller::Repeller()
{
	mLocation = Vec2f::zero();
}

Repeller::Repeller( Vec2f location )
{
	mLocation = location;
}