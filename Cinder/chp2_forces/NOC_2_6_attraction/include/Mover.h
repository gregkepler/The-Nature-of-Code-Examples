//
//  Mover.h
//  NOC_2_6_attraction
//
//  Created by Greg Kepler on 11/13/12.
//
//

#pragma once

class Mover {
public:
	Mover():
		mMass( 1.0f ),
		mLocation( ci::vec2( 400.0f, 50.0f ) ),
		mVelocity( ci::vec2( 1.0f, 0.0f ) ),
		mAcceleration( ci::vec2() )
	{};
	
	ci::vec2	mLocation, mVelocity, mAcceleration;
	float		mMass;
	
	void applyForce( ci::vec2 force );
	void update();
	void checkEdges();
	void display();
	void reset( ci::vec2 loc );
};
