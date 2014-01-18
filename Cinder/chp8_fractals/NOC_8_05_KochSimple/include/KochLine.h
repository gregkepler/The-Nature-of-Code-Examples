//
//  KochLine.h
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"

class KochLine {
	
	
public:
	KochLine( ci::Vec2f a, ci::Vec2f b );
	
	ci::Vec2f	mStart;
	ci::Vec2f	mEnd;
	
	void		display();
	ci::Vec2f	kochA();
	ci::Vec2f	kochB();
	ci::Vec2f	kochC();
	ci::Vec2f	kochD();
	ci::Vec2f	kochE();

};