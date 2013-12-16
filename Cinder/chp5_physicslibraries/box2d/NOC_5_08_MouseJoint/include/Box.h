//
//  Box.h
//  NOC_5_01_box2d_exercise_solved
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppBasic.h"
#include <Box2D/Box2D.h>

class Box {
public:
    Box();
    Box( b2World* const world, ci::Vec2f loc );
    ~Box();
    void    makeBody( ci::Vec2f center, float w, float h );
    void    display();
    bool    contains( b2Vec2 pt );
    void    killBody();
    
    float       mWidth, mHeight;
    b2Body      *mBody;
    b2World     *mWorld;
};