//
//  Node.h
//
//  Created by Greg Kepler
//
//

#pragma once

#include "cinder/app/AppNative.h"
#include "MSAPhysics2D.h"

class Node : public msa::physics::Particle2D {
	
public:
	Node( ci::Vec2f pos);
	void display();
	
	float						mRadius;
};