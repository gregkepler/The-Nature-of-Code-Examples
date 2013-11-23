//
//  Surface.h
//  NOC_5_03_ChainShape_SimpleApp
//
//  Created by Greg Kepler
//
//  An uneven surface boundary
//
//  Changed to SurfaceBoundary instead of Surface since Surface already exists in Cinder

#pragma once

#include "cinder/app/AppNative.h"
#include <Box2D/Box2D.h>

class SurfaceBoundary{
public:
    SurfaceBoundary( b2World* const world );
    void display();
    
    b2World             *mWorld;
	
	// We'll keep track of all of the surface points
    std::vector<b2Vec2>	surface;
};