//
//  Path.h
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"

class Path {
public:
	Path();
	void	display();
	
private:
	// A Path is line between two points (Vec2f objects)
	ci::Vec2f	mStart, mEnd;
	
	// A path has a radius, i.e how far is it ok for the boid to wander off
	float		mRadius;
};