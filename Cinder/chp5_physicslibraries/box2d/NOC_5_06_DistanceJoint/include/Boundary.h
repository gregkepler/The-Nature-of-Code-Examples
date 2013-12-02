//
//  Boundary.h
//  NOC_5_02_Boxes
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include <Box2D/Box2D.h>

class Boundary
{
public:
    Boundary( b2World* const world, ci::Vec2f pos, float w, float h, float a );
    void        display();
    
private:
    b2World     *mWorld;
    b2Body      *mBody;
    ci::Vec2f   mPos;
    float       mWidth, mHeight, mAngle;
};