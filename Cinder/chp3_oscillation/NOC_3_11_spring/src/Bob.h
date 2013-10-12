//
//  Bob.h
//  NOC_3_11_Spring
//
//  Created by Greg Kepler on 10/7/13.
//
//  Bob class, just like our regular Mover (location, velocity, acceleration, mass)
//

#pragma once
#include "cinder/app/AppBasic.h"

class Bob {
public:
	Bob();
	Bob( float x, float y );
	
	void update();
	void display();
	void applyForce( ci::Vec2f force );
	
	void clicked( ci::Vec2f mousePos );
	void drag( ci::Vec2f mousePos );
	void stopDragging();

	ci::Vec2f mLocation;
	ci::Vec2f mVelocity;
	
private:
	ci::Vec2f mAcceleration;
	float mMass = 24.0;
	
	// Arbitrary damping to simulate friction / drag
	float mDamping = 0.98;
	
	// For mouse interaction
	bool mDragging = false;
	ci::Vec2f mDragOffset;
};