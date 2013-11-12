//
//  Box.cpp
//  NOC_5_01_box2d_exercise_solved
//
//  Created by Greg Kepler on 11/10/13.
//
//

#include "cinder/app/AppNative.h"
#include <Box2D/Box2D.h>
#include "Box.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Box::Box()
{
    
}

Box::Box( b2World* const world, Vec2f loc )
{
    mWorld = world;
    mWidth = 16.0;
    mHeight = 16.0;
    
    // Build Body
    b2BodyDef bd;
    bd.type = b2_dynamicBody;
    bd.position.Set( loc.x, loc.y );
    body = world->CreateBody( &bd );
    
    // Define a polygon (this is what we use for a rectangle)
    b2PolygonShape ps;
    ps.SetAsBox( mWidth , mHeight );
    
    // Define a fixture
    b2FixtureDef fd;
    fd.shape = &ps;
    // Parameters that affect physics
    fd.density = 1.0;
    fd.friction = 0.3;
    fd.restitution = 0.5;
    
    // Attach Fixture to Body
    body->CreateFixture( &fd );
}

void Box::display()
{
    Vec2f pos = Vec2f(body->GetPosition().x, body->GetPosition().y);
    float a = body->GetAngle();
    
    glPushMatrix();
    gl::translate( pos );
    gl::rotate( -a );
    
    gl::color( Color8u::gray( 127 ) );
    Rectf rect = Rectf( -mWidth, -mHeight, mWidth, mHeight );
    gl::drawSolidRect( rect );
    
    gl::color( Color::black() );
    gl::drawStrokedRect( rect );
    
    glPopMatrix();
}