//
//  Attractor.h
//  NOC_2_6_attraction
//
//  Created by Greg Kepler on 11/22/12.
//
//

#pragma once

#include "Mover.h"

class Attractor {
public:
	Attractor():
		mDragging( false ),
		mRollover( false ),
		mMass( 20.0f ),
		mGravity( 1.0f ),
		mDragOffset( ci::vec2() ),
		mLocation( ci::vec2() )
	{}
	Attractor( const ci::vec2 &loc ):
		mDragging( false ),
		mRollover( false ),
		mMass( 20.0f ),
		mGravity( 1.0f ),
		mDragOffset( ci::vec2() ),
		mLocation( loc )
	{}
	ci::vec2 attract( const Mover &m );
	void display();
	void clicked( ci::vec2 mouseLoc );
	void hover( ci::vec2 mouseLoc );
	void stopDragging();
	void drag( ci::vec2 mouseLoc );
	
	float		mMass;			// Mass, tied to size
	float		mGravity;		// Gravitational Constant
	ci::vec2	mLocation;		// Location
	bool		mDragging;		// Is the object being dragged?
	bool		mRollover;		// Is the mouse over the ellipse?
	ci::vec2	mDragOffset;	// holds the offset for when object is clicked on
};
