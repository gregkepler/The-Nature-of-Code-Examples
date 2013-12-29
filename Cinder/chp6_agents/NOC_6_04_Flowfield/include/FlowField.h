//
//  FlowField.h
//
//  Created by Greg Kepler
//
//

#pragma once

#include "cinder/app/AppNative.h"

class FlowField {
	std::vector<std::vector<ci::Vec2f>> mField;				// A flow field is a two dimensional vector of Vec2fs
	int									mCols, mRows;		// Columns and Rows
	int									mResolution;		// How large is each "cell" of the flow field
	
	void		drawVector( ci::Vec2f v, float x, float y, float scale );
	
public:
	FlowField( int resolution );
	void		init();
	void display();
	ci::Vec2f	lookup( ci::Vec2f lookup );
	
};