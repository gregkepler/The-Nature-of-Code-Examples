//
//  Particle.cpp
//  NOC_5_03_ChainShape_SimpleApp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Particle::Particle( b2World* const world, Vec2f pos, float r )
{
    mWorld = world;
    mRadius = r;
    makeBody( pos, r );
}

void Particle::killBody()
{
    mWorld->DestroyBody( mBody );
}

// Is the particle ready for deletion?
bool Particle::done()
{
    // Let's find the screen position of the particle
    b2Vec2 pos = mBody->GetPosition();
    // Is it off the bottom of the screen?
    if( pos.y > getWindowHeight() + mRadius * 2 ) {
        killBody();
        return true;
    }
    return false;
}

void Particle::display()
{
    Vec2f pos = Vec2f( mBody->GetPosition().x, mBody->GetPosition().y );
    float a = toDegrees( mBody->GetAngle() );
    
    glPushMatrix();
    gl::translate( pos );
    gl::rotate( a );
    
    gl::color( Color8u::gray( 127 ) );
    gl::drawSolidEllipse( Vec2f::zero(), mRadius, mRadius );
    
    gl::color( Color::black() );
    gl::lineWidth( 2.0 );
    gl::drawStrokedEllipse( Vec2f::zero(), mRadius, mRadius );
    
    // Let's add a line so we can see the rotation
    gl::drawLine( Vec2f::zero(), Vec2f( mRadius, 0 ) );
    
    glPopMatrix();
}

// Here's our function that adds the particle to the Box2D world
void Particle::makeBody( Vec2f pos, float r )
{
    // Define the body
    b2BodyDef bd;
    // Set its position
    bd.position.Set( pos.x, pos.y );
    bd.type = b2_dynamicBody;
    mBody = mWorld->CreateBody( &bd );
    
    // Make the body's shape a circle
    b2CircleShape cs;
    cs.m_radius = r;
    
    b2FixtureDef fd;
    fd.shape = &cs;
    // Parameters that affect physics
    fd.density = 1.0;
    fd.friction = 0.01;
    fd.restitution = 0.3;
    
    mBody->CreateFixture( &fd );
    
    // Give it some initial random velocity
    mBody->SetLinearVelocity( b2Vec2( randFloat( -5.0, 5.0 ), randFloat( -5.0, 5.0 ) ) );
    mBody->SetAngularVelocity( randFloat( -5.0, 5.0 ) );
}

