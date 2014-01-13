//
//  Cell.h
//
//  Created by Greg Kepler
//
//

#pragma once

#include "cinder/app/AppNative.h"

class Cell {
	ci::Vec2f	mLoc;
	float		mWidth;
	
public:
	Cell();
	Cell( ci::Vec2f loc, float w );
	void	savePrevious();
	void	newState( int s );
	void	display();
	
	int		mState, mPrevious;
};