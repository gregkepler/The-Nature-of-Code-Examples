//
//  Mover.h
//  NOC_2_7_attraction_many
//
//  Created by Greg Kepler on 11/13/12.
//
//

#pragma once

class Mover {
public:
	Mover( float m, float x , float y );
	
	ci::vec2	mLocation, mVelocity, mAcceleration;
	float		mMass;
	float		mAngle, mAVelocity, mAAcceleration;
	
	void applyForce( ci::vec2 force );
	void update();
	void display();
};
