//
//  Obstacle.h
//
//  Created by Greg Kepler
//
//  Pathfinding w/ Genetic Algorithms
//
//  A class for an obstacle, just a simple rectangle that is drawn
//  and can check if a Rocket touches it
//
//  Also using this class for target location
//

#include "cinder/app/AppNative.h"

class Obstacle {
public:
	Obstacle( ci::Vec2f loc, float w, float h ): mLocation( loc ), mWidth( w ), mHeight( h ){};
	void display();
	
	ci::Vec2f	mLocation;
	float		mWidth, mHeight;
};