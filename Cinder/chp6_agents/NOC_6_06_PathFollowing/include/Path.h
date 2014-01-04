//
//  Path.h
//
//  Created by Greg Kepler
//
//

#pragma once

#include "cinder/app/AppNative.h"

class Path {
public:
	Path();
	// A Path is line between two points (Vec2f objects)
	ci::Vec2f	mStart, mEnd;
	
	// A path has a radius, i.e how far is it ok for the boid to wander off
	float		mRadius;
	
	// A Path is a vector of points (Vec2f objects)
	std::vector<ci::Vec2f> mPoints;
	
	void		addPoint( ci::Vec2f pt );
	void		display();
	ci::Vec2f	getStart();
	ci::Vec2f	getEnd();
	

};