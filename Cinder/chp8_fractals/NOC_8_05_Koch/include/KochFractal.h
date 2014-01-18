//
//  KochFractal.h
//  NOC_8_05_Koch
//
//  Created by Greg Kepler on 1/18/14.
//
//	A class to manage the list of line segments in the snowflake pattern
//

#include "cinder/app/AppNative.h"
#include "KochLine.h"

class KochFractal {
	int						mCount;
	std::vector<KochLine*>	mLines;
	ci::Vec2f				mStart, mEnd;
	

	std::vector<KochLine*>	iterate( std::vector<KochLine*> before );
	
public:
	KochFractal();
	
	void	render();
	void	nextLevel();
	void	restart();
	int		getCount();
};