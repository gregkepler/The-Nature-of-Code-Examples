//
//  Box.cpp
//  NOC_5_01_box2d_exercise_solved
//
//  Created by Greg Kepler on 11/10/13.
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
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
    
    mWidth = randFloat( 4.0, 16.0 ) / 2.0;
    mHeight = randFloat( 4.0, 16.0 ) / 2.0;
    
    makeBody( loc, mWidth, mHeight );
}

// This function adds the rectangle to the box2d world
void Box::makeBody( Vec2f loc, float w, float h )
{
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
    
    // Define the body and make it from the shape
    b2BodyDef bd;
    bd.type = b2_dynamicBody;
    bd.position.Set( loc.x, loc.y );
    mBody = mWorld->CreateBody( &bd );
    mBody->CreateFixture( &fd );
    
    // Give it some initial random velocity
    mBody->SetLinearVelocity( b2Vec2( randFloat( -5.0, 5.0 ), randFloat( -5.0, 5.0 ) ) );
    mBody->SetAngularVelocity( randFloat( -5.0, 5.0 ) );
}

void Box::killBody()
{
    mWorld->DestroyBody( mBody );
}

// Is the particle ready for deletion?
bool Box::done()
{
    // Let's find the screen position of the particle
    b2Vec2 pos = mBody->GetPosition();
    // Is it off the bottom of the screen?
    if( pos.y > getWindowHeight() + mWidth * mHeight ) {
        killBody();
        return true;
    }
    return false;
}

void Box::display()
{
    Vec2f pos = Vec2f( mBody->GetPosition().x, mBody->GetPosition().y );
    float a = mBody->GetAngle();
    
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