//
//  Box.h
//  NOC_5_01_box2d_exercise_solved
//
//  Created by Greg Kepler on 11/10/13.
//
//

#include "cinder/app/AppBasic.h"
#include <Box2D/Box2D.h>

class Box {
public:
    Box();
    Box( b2World* const world, ci::Vec2f loc );
    void    display();
    bool    done();
    void    killBody();
    
    float       mWidth, mHeight;
    b2Body      *mBody;
    b2World     *mWorld;
};