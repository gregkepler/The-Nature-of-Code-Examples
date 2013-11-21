//
//  Particle.cpp
//  NOC_5_03_ChainShape_SimpleApp
//
//  Created by Greg Kepler
//
//

#include "Particle.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace cinder;
using namespace std;

Particle::Particle( b2World* const world, Vec2f pos, float r )
{
    mWorld = world;
    mRadius = r;
    makeBody( pos, r );
}

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

void Particle::killBody()
{
    
}