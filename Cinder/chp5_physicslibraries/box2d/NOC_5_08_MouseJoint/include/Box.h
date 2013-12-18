//
//  Box.h
//
//  Created by Greg Kepler
//
//

#pragma once

#include "cinder/app/AppBasic.h"
#include <Box2D/Box2D.h>

class Box {
public:
    Box( b2World* const world, ci::Vec2f loc );
    void    makeBody( ci::Vec2f center, float w, float h );
    void    display();
    bool    contains( b2Vec2 pt );
    void    killBody();
    
    float       mWidth, mHeight;
    b2Body      *mBody;
    b2World     *mWorld;
};