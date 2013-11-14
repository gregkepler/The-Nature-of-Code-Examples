//
//  Boundary.cpp
//  NOC_5_02_Boxes
//
//  Created by Greg Kepler on 11/12/13.
//
//

#include "cinder/app/AppNAtive.h"
#include "Boundary.h"

using namespace ci;
using namespace cinder;
using namespace std;

Boundary::Boundary( b2World* const world, ci::Vec2f pos, float w, float h )
{
    mWorld = world;
    
    mPos = pos;
    mWidth = w;
    mHeight = h;

    // Define the polygon
    b2PolygonShape ps;
    
    // We're just a box
    ps.SetAsBox( mWidth/2, mHeight/2 );
    
    
    // Create the body
    b2BodyDef bd;
    bd.type = b2_staticBody;
    bd.position.Set( mPos.x, mPos.y );
    mBody = mWorld->CreateBody( &bd );
    
    // Attached the shape to the body using a Fixture
    mBody->CreateFixture( &ps, 1 );
}

// Draw the boundary, if it were at an angle we'd have to do something fancier
void Boundary::display()
{
    gl::color( Color::black() );
    gl::drawSolidRect( Rectf( mPos.x - ( mWidth / 2 ), mPos.y - (mHeight / 2), mPos.x + (mWidth/2), mPos.y + (mHeight/2) ) );
//    gl::drawSolidRect( Rectf( mPos.x-(mWidth/2), mPos.y-(mHeight/2), mWidth, mHeight ) );
//     gl::drawSolidRect( Rectf( 160.0, 20.0, 135.0, 10.0 ) );
}

